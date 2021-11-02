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

	// �������ݿ�
	QProcess process;
	process.start("C:/mysql/mysql-8.0.26-winx64/bin/mysql.exe");

	connect_flag = createConnection();

	// ������ʾ��table
	model = new QSqlTableModel(this);

}

void test1::exit_clicked()
{
	exit(0);
}

void test1::show_all_clicked() {
	// ��ʾ���еĲۺ���
	if (!connect_flag) {
		QMessageBox qmg;
		qmg.warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�������ݿ�ʧ�ܣ�"));
	}
	else {
		model->setTable("device_file");
		model->select();
		ui.tableView->setModel(model);
	}
}

void test1::query_clicked()
{
	// ��ѯ�Ĳۺ���
	QString id = ui.id_textEdit->toPlainText();
	QString device_id = ui.device_id_textEdit->toPlainText();
	QString device_name = ui.device_name_textEdit->toPlainText();
	if (id.isEmpty() && device_id.isEmpty() && device_name.isEmpty()) {
		QMessageBox qmg;
		qmg.warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���������ֶξ�Ϊ�գ�"));
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
	// ��ӵĲۺ���
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
		int ok = qmg.information(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("ȷ�ϼ�¼ID����е�idû�г�ͻ��"), QMessageBox::Yes, QMessageBox::No);
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
		qmg.warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���ʧ�ܣ�"));
	}

}

void test1::delete_clicked() {
	// ��ȡѡ�е���
	int curRow = ui.tableView->currentIndex().row();

	int ok = QMessageBox::warning(this, QString::fromLocal8Bit("ɾ����ǰ��!"),
		QString::fromLocal8Bit("ȷ��ɾ����ǰ���� "), QMessageBox::Yes, QMessageBox::No);
	if (ok == QMessageBox::No)
	{
		// �����ɾ���� ������ѡ��
		test1::show_all_clicked();
	}
	else {
		// �����ύ�� �����ݿ���ɾ������
		model->removeRow(curRow);// �ڱ����Ƴ�
		model->submitAll();// �����ݿ���ɾ��
		test1::show_all_clicked();
	}
}

void test1::modify_clicked() {
	int ok = QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),
		QString::fromLocal8Bit("ȷ���޸����ݿ⣿ "), QMessageBox::Yes, QMessageBox::No);
	if (ok == QMessageBox::Yes) {
		// ��ʼ�������
		model->database().transaction();
		if (model->submitAll()) {
			model->database().commit(); //�ύ
		}
		else {
			model->database().rollback(); //�ع�
			QMessageBox qmg;
			qmg.warning(this, QString::fromLocal8Bit("tableModel"),
				QString::fromLocal8Bit("���ݿ��������"));
		}
	}
	else {
		
	}
}