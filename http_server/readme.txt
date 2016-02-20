本程序用于构建一个类似于百度首页的服务器端程序，端口为8080，测试运行环境为redhat Enterprise 6 32位，编译为gcc4.4.6 。生成可执行文件myhttpd，可以用myhttp脚本进行控制，脚本支持参数为start、status、stop三种参数输入。默认打开模板default.html。
运行其他查询操作，依赖mysql数据库，需要创建数据库baidu如下：
	
	CREATE TABLE baidu 
	(ID int NOT NULL auto_increment,
	url varchar(100), 
	name varchar(100),
	description varchar(200),
	PRIMARY KEY (ID));

	CREATE UNIQUE INDEX baidu_id ON baidu (ID);

	CREATE INDEX baidu_name ON baidu (name);

