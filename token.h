#include <vector>
using namespace std;

enum TYPE {S_OPERATOR,S_IDENTIFIER,S_LITERAL,S_NUM};

struct Token {
  TYPE type;
  string value;
};

char stoppers[14] = {
    '>','<','+','-','*','/','=','(',')',',','`',' ','\'','"'
    };

bool is_stopper(char c){
  for(char s:stoppers){
    if(c==s)return true;
  }
  return false;
}

vector<Token> tokenize(string stmt){
  vector<Token> tokens;
  string buff;
  bool looking=false;
  char lookAhead = 'a';

  for(int i=0;i<stmt.length();i++){
      
    if(looking && lookAhead!=stmt[i]){
        
        buff += stmt[i];
        continue;
    } 
    if(is_stopper(stmt[i])){
      Token t;
      Token o;
    
      switch(stmt[i]){
        case '"':
        case '\'':
        case '`': 
           looking = !looking;
           lookAhead = stmt[i];
           t.type = S_LITERAL;
          t.value = buff;
          if(buff!="" && !looking){
            tokens.push_back(t);
            buff="";
          }
           break;  
        case '>':
        case '=':
        case '<':
        case '+':
        case '-':
        case '/':
        case '*':  
          t.type = S_IDENTIFIER;
          t.value = buff;
          if(buff!=""){
            tokens.push_back(t);
          }
          buff="";
          o.type= S_OPERATOR;
          o.value = stmt[i];
          tokens.push_back(o);
          break;
        case ',':  
        case ' ':
        case '(':
           if(buff==""){
               break;
           }
           t.type = S_IDENTIFIER;
           t.value = buff;
           tokens.push_back(t);
           buff="";
           break;
      }

     
      continue;
    }
    buff += stmt[i];
  }

  Token t;
    t.type = S_IDENTIFIER;
    t.value = buff;
  if(buff!=""){
   tokens.push_back(t);
  }
  

  return tokens;
}

string getType(TYPE t){
  switch(t){
    case 0 :
      return "Operator";
    case 1:
      return "Identifier";
    case 2:
      return "Literal";
    case 3:
      return "Number";  

  }
  return "Operator not mentioned";
}

void printTokens(vector<Token> v){
  for(Token s:v){
    cout << getType(s.type) << " --> " << s.value <<endl;
  }
}