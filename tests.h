#include <vector>

using namespace std;

string stmts[12]={
  "select * from table_name where a>3",
  "select   * from   table_name where a >  3",
  "select * from `table_name` limit 5",
  "select count(a) AS p from table_name where a >= 3 ",
  "select a,b,c from table_name order by 3 limit 1",
  "select SUBSTR(concat(a,b),3,4) as e from table_name",
  "select SUBSTR(concat(a,'.. ... ..'),3,4) as e from table_name",
   "select SUBSTR(concat(a,'.. ... ..'),3,4) as e from table_name and b like \"%cache\"",
 "insert into table_name ('a','b','c') values (1,2,'thanks')",
 "select * from dbname.table_name where 1",
 "select (select p from table2 where p=a) from table1 ",
 "select (subtotal+tax) as total from orders"
};


void run_tests(){
  
  for(string stmt:stmts){
     cout<<stmt<<endl;
     vector<Token> v= tokenize(stmt);
     printTokens(v);
     cout << "----------------------------------\n";
  }
}