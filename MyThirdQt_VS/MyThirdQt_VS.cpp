#include "MyThirdQt_VS.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QtWidgets/qmessagebox.h>
#include <QProcess>
#include "createConnection.cpp"

bool connect_flag = false;

test1::test1(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// 连接数据库
	QProcess process;
	process.start("C:/mysql/mysql-8.0.26-winx64/bin/mysql.exe");

	connect_flag = createConnection();

	// 设置显示的table
	model = new QSqlTableModel(this);

}

void test1::exit_clicked()
{
	exit(0);
}

void test1::show_all_clicked() {
	// 显示所有的槽函数
	if (!connect_flag) {
		QMessageBox qmg;
		qmg.warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("连接数据库失败！"));
	}
	else {
		model->setTable("device_file");
		model->select();
		ui.tableView->setModel(model);
	}
}

void test1::query_clicked()
{
	// 查询的槽函数
	QString id = ui.id_textEdit->toPlainText();
	QString device_id = ui.device_id_textEdit->toPlainText();
	QString device_name = ui.device_name_textEdit->toPlainText();
	if (id.isEmpty() && device_id.isEmpty() && device_name.isEmpty()) {
		QMessageBox qmg;
		qmg.warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("不能所有字段均为空！"));
	}
	else {
		if (!id.isEmpty()) {
			model->setFilter(QString("id = '%1'").arg(id));
			model->select();
		}
		else {
			if (!device_id.isEmpty()) {
				model->setFilter(QString("device_id = '%1'").arg(device_id));
				model->select();
			}
			else {
				model->setFilter(QString("device_name = '%1'").arg(device_name));
				model->select();
			}
		}
	}
}

void test1::add_clicked() {
	QString sql;
	// 添加的槽函数
	QString id = ui.id_textEdit->toPlainText();
	QString device_id = ui.device_id_textEdit->toPlainText();
	QString device_name = ui.device_name_textEdit->toPlainText();
	if (id.isEmpty()) {
		sql = "insert into device_file(device_id, device_name) values('" + device_id + "','" + device_name + "')";
	}
	else {
		sql = "insert into device_file(id, device_id, device_name) values(" + id + ",'" + device_id + "','" + device_name + "')";
	}


	if (connect_flag) {
		QMessageBox qmg;
		int ok = qmg.information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("确认记录ID与表中的id没有冲突？"), QMessageBox::Yes, QMessageBox::No);
		if (ok == QMessageBox::No) {
			qmg.close();
		}
		else {
			QSqlQuery query(db);
			query.exec(sql);
			ui.id_textEdit->clear();
			ui.device_id_textEdit->clear();
			ui.device_name_textEdit->clear();
			test1::show_all_clicked();
		}
	}
	else {
		QMessageBox qmg;
		qmg.warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("添加失败！"));
	}

}

void test1::delete_clicked() {
	// 获取选中的行
	int curRow = ui.tableView->currentIndex().row();

	int ok = QMessageBox::warning(this, QString::fromLocal8Bit("删除当前行!"),
		QString::fromLocal8Bit("确认删除当前行吗？ "), QMessageBox::Yes, QMessageBox::No);
	if (ok == QMessageBox::No)
	{
		// 如果不删除， 则消除选择
		test1::show_all_clicked();
	}
	else {
		// 否则提交， 在数据库中删除该行
		model->removeRow(curRow);// 在表中移除
		model->submitAll();// 在数据库中删除
		test1::show_all_clicked();
	}
}

void test1::modify_clicked() {
	int ok = QMessageBox::information(this, QString::fromLocal8Bit("提示"),
		QString::fromLocal8Bit("确认修改数据库？ "), QMessageBox::Yes, QMessageBox::No);
	if (ok == QMessageBox::Yes) {
		// 开始事务操作
		model->database().transaction();
		if (model->submitAll()) {
			model->database().commit(); //提交
		}
		else {
			model->database().rollback(); //回滚
			QMessageBox qmg;
			qmg.warning(this, QString::fromLocal8Bit("tableModel"),
				QString::fromLocal8Bit("数据库操作错误！"));
		}
	}
	else {
		
	}
}