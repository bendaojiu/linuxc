���������ڹ���һ�������ڰٶ���ҳ�ķ������˳��򣬶˿�Ϊ8080���������л���Ϊredhat Enterprise 6 32λ������Ϊgcc4.4.6 �����ɿ�ִ���ļ�myhttpd��������myhttp�ű����п��ƣ��ű�֧�ֲ���Ϊstart��status��stop���ֲ������롣Ĭ�ϴ�ģ��default.html��
����������ѯ����������mysql���ݿ⣬��Ҫ�������ݿ�baidu���£�
	
	CREATE TABLE baidu 
	(ID int NOT NULL auto_increment,
	url varchar(100), 
	name varchar(100),
	description varchar(200),
	PRIMARY KEY (ID));

	CREATE UNIQUE INDEX baidu_id ON baidu (ID);

	CREATE INDEX baidu_name ON baidu (name);

