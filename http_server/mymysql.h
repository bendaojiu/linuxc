#ifndef MYMYSQL_H_
#define MYMYSQL_H_

int sql_connect(const char *Hostname, const char *User, const char *Passwork, const char *DBName);
int sql_disconnect();
int query_result(const char *name, const char **buf);

#endif
