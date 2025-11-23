#include<iostream>
#include<vector>
#include<string>
#include<cctype>  // to check the type of character
#include<algorithm> // for reverse only
using namespace std;

class Stack{
    public:
    vector<char> stack;
    int top=-1;
    
        void Push(char val){
            stack.push_back(val);
            top++;
        }

        void Pop(){
            if(top>-1) {
                char val=stack[top];
                stack.pop_back();
                top--;
            } else  {
            cout << "Stack Underflow! Cannot pop."<<endl;
            }
        }

        char Peek(){
        if(top>-1){
            return stack[top];
        }else{
            cout<<"Stack is empty"<<endl;
            return '\0'; 
            }
        }

        bool Underflow(){
            return top==-1;
    }


};

int precedence(char op){
    if(op=='^') return 3;
    if(op=='*' || op=='/') return 2;
    if(op=='+' || op=='-') return 1;
    return 0;
}
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}



string prefix_to_infix(string &str) {
    vector<string> s; // Using a vector<string> directly as the stack
    int n = str.length();

    for (int i = n - 1; i >= 0; i--) {
        char current_char = str[i];
        if (isalnum(current_char)) {
            // Push operands as a string
            string operand_str(1, current_char);
            s.push_back(operand_str);
        } else if (isOperator(current_char)) {
            if (s.size() < 2) {
                return "Error: Invalid prefix expression";
            }
            // Pop the two string operands
            string op1 = s.back();
            s.pop_back();
            string op2 = s.back();
            s.pop_back();

            // Create the new infix string and push it back
            string new_infix = "(" + op1 + current_char + op2 + ")";
            s.push_back(new_infix);
        }
    }

    if (s.size() == 1) {
        return s[0];
    } else {
        return "Error: Invalid prefix expression";
    }
}

string infix_to_postfix(string &str){
    Stack s;
    string result;
    for(char ch : str){
    if(isalnum(ch)){
        result += ch;
    }
    else if(ch=='('){
        s.Push(ch);
    }else if(ch==')'){
        while(!s.Underflow() && s.Peek() != '('){
            result += s.Peek();
            s.Pop();
        }
          if(!s.Underflow() && s.Peek() == '(') {
                 s.Pop(); // remove '('
            }
    }
    else { // operator
        while(!s.Underflow() && precedence(s.Peek()) >= precedence(ch)){
              if(s.Peek() == '^' && ch == '^') {
                    // This handles right associativity for exponentiation
                    break; 
                }
            result += s.Peek();
            s.Pop();
            }
        s.Push(ch); 
        }
    }
    while(!s.Underflow()){
        result += s.Peek();
        s.Pop();
    }
    return result;
}





string infix_to_prefix(string &str){
    string result;
    reverse(str.begin(),str.end());
        for(char &ch : str){
        if(ch == '(') {
            ch = ')';
        }else if(ch == ')'){
            ch = '(';
            }
        }
        result=infix_to_postfix(str);
        reverse(result.begin(),result.end());
        return result;

}

int postfix_evaluation(string &str){
    vector<int> s;
    int top = -1;
    for(char ch : str){
        if(isdigit(ch)){
            s.push_back(ch-'0');
            top++;
        } else if (ch=='+' || ch=='-' || ch=='*' || ch=='/') {
            if (s.size() < 2) {
                cout << "Invalid postfix expression: not enough operands." << endl;
                return -1;
            }

            int op2 = s[top];
            s.pop_back();
            top--;
            int op1 = s[top];
            s.pop_back();
            top--;
            
            if(ch=='+'){
                s.push_back(op1 + op2);
                top++;
            } else if(ch=='-'){
                s.push_back(op1 - op2);
                top++;
            } else if(ch=='*'){
                s.push_back(op1 * op2);
                top++;
            } else if(ch=='/'){
                // This will crash on division by zero
                s.push_back(op1 / op2);
                top++;
            }
        }
        
    }

    if(top == 0 && s.size() == 1){
        return s[top];
    } else {
        cout << "Invalid postfix expression: too many operands or malformed." << endl;
        return -1;
    }
}





int main(){
    int v,z=0;

    do{
        cout<<"____________Menu_______________"<<endl;
        cout<<"1. From prefix to infix"<<endl;
        cout<<"2. From infix to postfix"<<endl;
        cout<<"3. From infix to prefix"<<endl;
        cout<<"4. From prefix to infix then from infix to postfix and postfix evaluation"<<endl;
        cout<<"5. To Exit the program"<<endl;
        cout<<"Enter your choice: ";
        cin>>v;
        string expr;
        switch(v){
            case 1:{
                cout<<"Enter the prefix expression: ";
                cin>>expr;
                string result=prefix_to_infix(expr);
                cout<<"The Infix expression is -> "<<result<<endl;
                break;
            }
            case 2:{
                cout<<"Enter the infix expression: ";
                cin>>expr;
                string result=infix_to_postfix(expr);
                cout<<"The Postfix expression is -> "<<result<<endl;
                break;

            }
            case 3:{
                cout<<"Enter the infix expression: ";
                cin>>expr;
                string result=infix_to_prefix(expr);
                cout<<"The Prefix expression is -> "<<result<<endl;
                break;

            }
            case 4:{
                cout<<"Enter the prefix expression: ";
                cin>>expr;
                string prefix=expr;
                string infix=prefix_to_infix(expr);
                string postfix=infix_to_postfix(infix);
                int result=postfix_evaluation(postfix);
                cout<<"The prefix expression -> "<<prefix<<endl;
                cout<<"The infix expression -> "<<infix<<endl;
                cout<<"The postfix expression -> "<<postfix<<endl;
                cout<<"The postfix evaluation -> "<<result<<endl;
                break;
            }
            
            case 5:{
                z=1;
                cout<<"The Program has ended"<<endl;
                cout<<"_________________________________________________________________________________________";
                break;
            }
            default:{
                cout<<"Enter a valid Choice << endl";
                break;
            }
        }

    }while(z==0);

    return 0;
}