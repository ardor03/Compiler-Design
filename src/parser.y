%{
#include<bits/stdc++.h>
using namespace std;
int yylex();
void yyerror(const char *s);
extern int yylineno;
extern FILE *yyin;
extern char * yytext;

// parser for python 3.6

int root=-1;
int line=0;

uint countnode=0;
map<int, pair<string, vector<int> > > tree;
map<int, int> parent;



int makenode(string name){
    countnode++;
    vector<int>childs;
    tree[countnode].first=name;
    tree[countnode].second=childs;
    return countnode;
}

void addChild(int p, int c){
    tree[p].second.push_back(c);
    parent[c] = p;
}

void writeDotFile(const std::map<int, std::pair<std::string, std::vector<int>>> &tree, const std::string &filename) {
    std::ofstream dotFile(filename);
    if (!dotFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    dotFile << "digraph Tree {\n";
    
    for (const auto &node : tree) {
        int nodeId = node.first;
        std::string label = node.second.first;
        std::vector<int> children = node.second.second;

        // set<string> BytePrefix = {"b" | "B" | "br" | "Br" | "bR" | "BR" | "rb" | "rB" | "Rb" | "RB"}
        set<string> BytePrefix = {"b", "B", "br", "Br", "bR", "BR", "rb", "rB", "Rb", "RB"};
        // Write node
        if (label[label.size() - 1] == '\"') {
            // remove last character and prefix upto "
            label = label.substr(0, label.size() - 2);
            int i = 0;
            while (i < label.size() && label[i] != '\"') {
                i++;
                
            }
            label = label.substr(0,i) + "\\\"" + label.substr(i + 1, label.size()) + "\\\"";
        }

        dotFile << "    " << nodeId << " [label=\"" << label << "\"];\n";

        // Write edges
        for (int child : children) {
            if(child != -1) dotFile << "    " << nodeId << " -> " << child << ";\n";
        }
    }

    dotFile << "}\n";
    
    dotFile.close();
}


%}





%union {
    
    char * sval;
    int id;
    // for int num
    int intNumber;
    // for float num also
    float fltNumber;
}


%token<fltNumber> LITERAL_FLOAT
%token<intNumber> LITERAL_INT

%token KEY_FALS KEY_NONE KEY_TRU KEY_AS KEY_ASSERT KEY_ASYNC KEY_AWAIT KEY_BREAK KEY_CLASS KEY_CONTINUE KEY_DEF KEY_DEL KEY_ELIF KEY_ELSE KEY_EXCEPT KEY_FINALLY KEY_FOR KEY_FROM KEY_GLOBAL KEY_IF KEY_IMPORT KEY_IN KEY_IS KEY_LAMBDA KEY_NONLOCAL KEY_PASS KEY_RAISE KEY_RETURN KEY_TRY KEY_WHILE KEY_WITH KEY_YIELD 

%token <sval> IDENTIFIER

%token <sval> RES_ID_SELF
%token <sval> RES_ID_INIT
%token <sval> RES_ID_MAIN

%token KEY_INT KEY_FLOAT KEY_STR KEY_BOOL

%token OP_PLUS OP_MINUS OP_TIMES OP_DIVIDE OP_FLOOR OP_MOD OP_EXP OP_LSHIFT OP_RSHIFT OP_BITWISE_AND OP_BITWISE_OR OP_BITWISE_XOR OP_BITWISE_NOT OP_WALRUS OP_LESS OP_GREATER OP_LESS_EQ OP_GREATER_EQ OP_EQ OP_NOT_EQ OP_LOGICAL_NOT OP_LOGICAL_OR OP_LOGICAL_AND 

%token NEWLINE

%token <sval>STRING
%token <sval>BYTESTRING

%token KEY_LIST

%token STMT_PRINT STMT_RANGE


%token DELIM_LPAR DELIM_RPAR DELIM_LBRACKET DELIM_RBRACKET DELIM_LBRACE DELIM_RBRACE DELIM_COMMA DELIM_COLON DELIM_DOT DELIM_SEMICOLON DELIM_ARROW

%token DELIM_OP_AT DELIM_ASSIGN DELIM_PLUS_EQ DELIM_MINUS_EQ DELIM_TIMES_EQ DELIM_DIVIDE_EQ DELIM_FLOOR_EQ DELIM_MOD_EQ DELIM_MATMUL_EQ DELIM_AND_EQ DELIM_OR_EQ DELIM_XOR_EQ DELIM_RSHIFT_EQ DELIM_LSHIFT_EQ DELIM_EXP_EQ


/* %token KEY_FALS */

%left OP_PLUS OP_MINUS OP_TIMES OP_DIVIDE OP_FLOOR
%left OP_MOD OP_LSHIFT OP_RSHIFT 
%left OP_LESS OP_GREATER OP_LESS_EQ OP_GREATER_EQ 
%left OP_EQ OP_NOT_EQ
%left OP_BITWISE_AND OP_BITWISE_OR OP_BITWISE_XOR 
%left OP_LOGICAL_OR OP_LOGICAL_AND
%left DELIM_OP_AT


%right OP_BITWSIE_NOT OP_WALRUS OP_LOGICAL_NOT
%right OP_EXP 
%right DELIM_ASSIGN DELIM_PLUS_EQ DELIM_MINUS_EQ DELIM_TIMES_EQ DELIM_DIVIDE_EQ DELIM_FLOOR_EQ DELIM_MOD_EQ DELIM_MATMUL_EQ DELIM_AND_EQ DELIM_OR_EQ DELIM_XOR_EQ DELIM_RSHIFT_EQ DELIM_LSHIFT_EQ DELIM_EXP_EQ 



%token ENDMARKER






%token INDENT
%token DEDENT
/* tokens for parentheses */
/* %token LPAREN RPAREN */
/* tokens for brackets */
/* %token LBRACKET RBRACKET */
/* tokens for braces */
/* %token LBRACE RBRACE */

/*
%type <node> program
%type <node> statements
%type <node> statement assign_statement if_statement while_statement break_statement
%type <node> expression primary_expression negated_expression
%type <node> block
%type <node> condition
%type <node> elif_blocks else_block

*/


%type <id> input
%type <id> statements
%type <id> statement simplestatement expressionstatement delstatement returnstatement globalstatement nonlocalstatement assign_statement assignments Ids Variable_Declaration Type_Declaration Primitive_Type NumericType List_Type List_expression expression logical_or_expression logical_and_expression bitwise_or_expression bitwise_xor_expression bitwise_and_expression equality_expression relational_expression shift_expression additive_expression multiplicative_expression exponentiation_expression negated_expression primary_expression funccall arguments compoundstatement ifstatement elifblocks elifblock elseblock whilestatement forstatement for_expression ForList funcdef params Return_Type Suite classdef Names raisestatement




/* %start CompilationUnit */

%start input



%%



    /* take care of precedence for LR1 grammer, non ambiguous grammer */

    

/* Start symbol */
    input 
        : statements END  {
            cout << "input" << endl;
            int uid = makenode("input");
            addChild(uid, $1);
            int child = makenode("ENDMARKER");
            addChild(uid, child);
            root = uid;
            $$ = uid;

            }
        |  END {
            cout << "input" << endl;
            int uid = makenode("input");
            int child = makenode("ENDMARKER");
            addChild(uid, child);
            root = uid;
            $$ = uid;}
        ;
/* Used in Input */
    END 
        : NEWLINE END  { cout << "end newline" << endl;}
        | ENDMARKER { cout << "end" << endl; }
        ;

/*  */
    statements : 
        statement   { 
            cout << "statements" << endl;
            $$ = $1;
            

        }
        | statements statement { 
            cout << "statements" << endl;
            int uid = makenode("statements");
            addChild(uid, $1);
            addChild(uid, $2);
            $$ = uid;
        }
        ;

    

    statement : 
        simplestatement NEWLINE  {
            cout << "statement" << endl;
            $$ = $1;
        }
        | compoundstatement  { 
            cout << "statement" << endl;
            $$ = $1;
        }
        ;


    
    /* SIMPLE STATEMENT */
    simplestatement :
        expressionstatement          { 
            cout << "simple statement" << endl;
            $$ = $1;
        }
        /* | printstatement             { cout << "simple statement" << endl;} */
        | delstatement              { 
            cout << "simple statement" << endl;
            $$ = $1;
        }
        | KEY_BREAK           {
            cout << "simple break statement" << endl;
            $$ = makenode("break");

        }
        | KEY_CONTINUE         { 
            cout << "simple continue statement" << endl;
            $$ = makenode("continue");
        }
        | KEY_PASS  {
            cout << "simple pass statement" << endl;
            $$ = makenode("pass");
        }
        | globalstatement         { 
            cout << "simple statement" << endl;
            $$ = $1;
        }
        | nonlocalstatement      { 
            cout << "simple statement" << endl;
            $$ = $1;
        }
        | assign_statement        { 
            cout << "simple statement" << endl;
            $$ = $1;
        }
        | returnstatement         { 
            cout << "simple statement" << endl;
            $$ = $1;
        }
        | expression                 { 
            cout << "simple expression" << endl;
            $$ = $1;
        }
        | raisestatement           { 
            cout << "simple statement" << endl;
            $$ = $1;
        }
        ;
        


    
    expressionstatement :
        Variable_Declaration    { 
            cout << "expression statement" << endl;
            $$ = $1;
        }
        /* | RES_ID_SELF DELIM_DOT Variable_Declaration  {
            int uid = makenode("declaration");
            addChild(uid, makenode("self"));
            int child = makenode("dot");
            addChild(uid, child);
            addChild(child, $3);
            $$ = uid;

        } */
        ;
    delstatement :
        KEY_DEL expression   { 
            cout << "del statement" << endl;
            int uid = makenode("del");
            addChild(uid, $2);
            $$ = uid;
            

        }
        ;
    
    returnstatement :
        KEY_RETURN expression   { 
            cout << "return statement" << endl;
            int uid = makenode("return");
            addChild(uid, $2);
            $$ = uid;

        }
        | KEY_RETURN  { 
            cout << "return statement" << endl;
            $$ = makenode("return");

        }
        ;
   
    raisestatement :
        KEY_RAISE expression   { 
            cout << "raise statement" << endl;
            int uid = makenode("raise");
            addChild(uid, $2);
            $$ = uid;
        }
        | KEY_RAISE  { 
            cout << "raise statement" << endl;
            $$ = makenode("raise");
        }
        ;


    globalstatement :
        KEY_GLOBAL Names     { 
            cout << "global statement" << endl;
            int uid = makenode("global");
            addChild(uid, $2);
            $$ = uid;
        }
        ;
    
    nonlocalstatement :
        KEY_NONLOCAL Names   { 
            cout << "nonlocal statement" << endl;
            int uid = makenode("nonlocal");
            addChild(uid, $2);
            $$ = uid;
        }
        ;

    
    /* Assignment Statement */

    assign_statement:
        assignments
        | Ids DELIM_PLUS_EQ expression  {
            int uid = makenode("+=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | Ids DELIM_MINUS_EQ expression  {
            int uid = makenode("-=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        | Ids DELIM_TIMES_EQ expression  { 
            int uid = makenode("*=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | Ids DELIM_DIVIDE_EQ expression  {
            int uid = makenode("/=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        | Ids DELIM_FLOOR_EQ expression  {
            int uid = makenode("//=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        | Ids DELIM_MOD_EQ expression  { 
            int uid = makenode("%=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | Ids DELIM_MATMUL_EQ expression  { 
            int uid = makenode("@=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | Ids DELIM_AND_EQ expression  {
            int uid = makenode("&=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        | Ids DELIM_OR_EQ expression  { 
            int uid = makenode("|=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | Ids DELIM_XOR_EQ expression  { 
            int uid = makenode("^=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | Ids DELIM_RSHIFT_EQ expression  {
            int uid = makenode(">>=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        | Ids DELIM_LSHIFT_EQ expression  { 
            int uid = makenode("<<=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | Ids DELIM_EXP_EQ expression  { 
            int uid = makenode("**=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        ; 

    assignments :
        Ids DELIM_ASSIGN assignments { 
            cout << "assignments" << endl;
            int uid = makenode("=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | Ids DELIM_ASSIGN expression  {
            cout << "assignments" << endl;
            int uid = makenode("=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }


    Ids : 
        Names {
            cout << "ids" << endl;
            $$ = $1;
         }
        | Names DELIM_LBRACKET expression DELIM_RBRACKET {
            cout << "ids" << endl;
            int uid = makenode("atom_expr");

            addChild(uid, $1);
            int child= makenode("[]");
            addChild(uid, child);
            addChild(child, $3);

            $$ = uid;
        }
        | RES_ID_SELF DELIM_DOT Ids {
            cout << "ids" << endl;
            int uid = makenode("atomic_expr");
            addChild(uid, makenode("self"));
            int dot = makenode(".");
            addChild(uid, dot);
            addChild(dot, $3);

            // addChild(uid, $3);
            $$ = uid;
        }
        | IDENTIFIER DELIM_DOT Ids {
            // cout << "ids" << endl;
            int uid = makenode("atomic_expr");
            addChild(uid, makenode($1));
            int dot = makenode(".");
            addChild(uid, dot);
            addChild(dot, $3);
            $$ = uid;
        }

        ;



    /* TYPE DECLARATION */
    Variable_Declaration :
        Type_Declaration DELIM_ASSIGN expression { 
            cout << "variable" << endl;
            int uid = makenode("=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
            

        }
        /* | Names DELIM_COLON List_Type DELIM_ASSIGN expression { cout << "list" << endl;} */
        | Type_Declaration {
            cout << "variable" << endl;
            $$ = $1;
        }
        /* | Names DELIM_COLON List_Type { cout << "list_dec" << endl;} */
        ;

    Type_Declaration :
        Names DELIM_COLON Primitive_Type  {
            int uid = makenode(":");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        /* | Names DELIM_COLON List_Type { cout << "list" << endl;} 
        |        */
        | RES_ID_SELF DELIM_DOT Type_Declaration { 
            int uid = makenode("atomic_expr");
            addChild(uid, makenode("self"));
            int dot = makenode(".");
            addChild(uid, dot);
            addChild(dot, $3);
            $$ = uid;
        }
        ;


    Primitive_Type : 
        NumericType   { 
            cout << "numeric" << endl;
            $$ = $1;
        }
        | KEY_STR     { 
            cout << "string" << endl;
            $$ = makenode("str");
        }
        | KEY_BOOL    {
             cout << "bool" << endl;
                $$ = makenode("bool"); 

        }
        | List_Type   {
             cout << "list" << endl;
                $$ = $1;
        }
        | Names       {
            cout << "primitive" << endl;
            $$ = $1;
        }

        ; 
    
    NumericType : 
        KEY_INT       { 
            cout << "int" << endl;
            $$ = makenode("int");
        }
        | KEY_FLOAT   {
            cout << "float" << endl;
            $$ = makenode("float");
        }
        ;

    /* LIST DECLARATION */

    List_Type :
        KEY_LIST DELIM_LBRACKET Primitive_Type DELIM_RBRACKET { 
            cout << "list_type" << endl;
            int uid = makenode("atom_expr");
            addChild(uid, makenode("list"));
            int child = makenode("[]");
            addChild(child, $3);
            addChild(uid, child);
            $$ = uid;
        }
        ;

  
    List_expression :
        expression DELIM_COMMA List_expression  { 
            cout << "list" << endl;
            int uid = makenode(",");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | expression { 
            cout << "list" << endl;
            $$ = $1;
        }
        | %empty {
            $$ = -1;
        }
        

    
    /* EXPRESSIONS */

    expression 
    : logical_or_expression { 
        cout << "expression" << endl;
        $$ = $1;
    }
    ;

    logical_or_expression 
        : logical_and_expression    {
            cout << "logical or" << endl;
            $$ = $1;
        }
        | logical_or_expression OP_LOGICAL_OR logical_and_expression { 
            cout << "logical or" << endl;
            int uid = makenode("or");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        ;

    logical_and_expression 
        : bitwise_or_expression  { 
            cout << "logical and" << endl;
            $$ = $1;
        }
        | logical_and_expression OP_LOGICAL_AND bitwise_or_expression { 
            cout << "logical and" << endl;
            int uid = makenode("and");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        ;

    bitwise_or_expression 
        : bitwise_xor_expression   { 
            cout << "bitwise or" << endl;
            $$ = $1;
        }
        | bitwise_or_expression OP_BITWISE_OR bitwise_xor_expression { 
            cout << "bitwise or" << endl;
            int uid = makenode("|");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        ;

    bitwise_xor_expression 
        : bitwise_and_expression   { 
            cout << "bitwise xor" << endl;
            $$ = $1;
        }
        | bitwise_xor_expression OP_BITWISE_XOR bitwise_and_expression { 
            cout << "bitwise xor" << endl;
            int uid = makenode("^");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
    ;

    bitwise_and_expression 
        : equality_expression    { 
            cout << "bitwise and" << endl;
            $$ = $1;
        }
        | bitwise_and_expression OP_BITWISE_AND equality_expression { 
            cout << "bitwise and" << endl;
            int uid = makenode("&");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        ;

    equality_expression 
        : relational_expression  { 
            cout << "equality expression" << endl;
            $$ = $1;
        }
        | equality_expression OP_EQ relational_expression {  
            cout << "equality expression" << endl;
            int uid = makenode("==");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | equality_expression OP_NOT_EQ relational_expression {
            cout << "equality expression" << endl;
            int uid = makenode("!=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | equality_expression OP_WALRUS relational_expression {
            cout << "equality expression" << endl;
            int uid = makenode(":=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | equality_expression KEY_IS relational_expression {
            cout << "equality expression" << endl;
            int uid = makenode("=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | equality_expression KEY_IN Ids {
            cout << "equality expression" << endl;
            int uid = makenode("in");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | equality_expression OP_LOGICAL_NOT KEY_IN Ids {
            cout << "equality expression" << endl;
            int uid = makenode("!=");
            addChild(uid, $1);
            addChild(uid, $4);
            $$ = uid;
        }
        ;

    relational_expression 
        : shift_expression  { 
            cout << "relational expression" << endl;
            $$ = $1;
        }
        | relational_expression OP_LESS shift_expression { 
            cout << "relational expression" << endl;
            int uid = makenode("<");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | relational_expression OP_GREATER shift_expression { 
            cout << "relational expression" << endl;
            int uid = makenode(">");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | relational_expression OP_LESS_EQ shift_expression {
            cout << "relational expression" << endl;
            int uid = makenode("<=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        | relational_expression OP_GREATER_EQ shift_expression {
            cout << "relational expression" << endl;
            int uid = makenode(">=");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        ;

    shift_expression 
        : additive_expression
        | shift_expression OP_LSHIFT additive_expression {
            cout << "shift expression" << endl;
            int uid = makenode("<<");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        | shift_expression OP_RSHIFT additive_expression { 
            cout << "shift expression" << endl;
            int uid = makenode(">>");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        ;

    additive_expression 
        : multiplicative_expression  { 
            cout << "additive expression" << endl;
            $$ = $1;
        }
        | additive_expression OP_PLUS multiplicative_expression { 
            cout << "additive expression" << endl;
            int uid = makenode("+");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | additive_expression OP_MINUS multiplicative_expression { 
            cout << "additive expression" << endl;
            int uid = makenode("-");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        ;

    multiplicative_expression 
        : exponentiation_expression   { 
            cout << "multiplicative expression" << endl;
            $$ = $1;
        }
        | multiplicative_expression OP_TIMES exponentiation_expression { 
            cout << "multiplicative expression" << endl;
            int uid = makenode("*");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | multiplicative_expression OP_DIVIDE exponentiation_expression {
            cout << "multiplicative expression" << endl;
            int uid = makenode("/");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        | multiplicative_expression OP_FLOOR exponentiation_expression {
            cout << "multiplicative expression" << endl;
            int uid = makenode("//");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        | multiplicative_expression OP_MOD exponentiation_expression { 
            cout << "multiplicative expression" << endl;
            int uid = makenode("%");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        ;

    exponentiation_expression 
        : negated_expression     {
            cout << "exponentiation expression" << endl;
            $$ = $1;
         }
        | negated_expression OP_EXP exponentiation_expression {
            cout << "exponentiation expression" << endl;
            int uid = makenode("**");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
         }
        ;

    negated_expression 
        : primary_expression    {
            cout << "negated expression" << endl;
            $$ = $1;
        }
        | OP_MINUS negated_expression {
            cout << "negated expression" << endl;
            int uid = makenode("-");
            addChild(uid, $2);
            $$ = uid;
         }
        | OP_LOGICAL_NOT negated_expression { 
            cout << "negated expression" << endl;
            int uid = makenode("not");
            addChild(uid, $2);
            $$ = uid;
        }
        | OP_BITWISE_NOT negated_expression {
            cout << "negated expression" << endl;
            int uid = makenode("~");
            addChild(uid, $2);
            $$ = uid;
         }
        | OP_PLUS negated_expression { 
            cout << "negated expression" << endl;
            int uid = makenode("+");
            addChild(uid, $2);
            $$ = uid;

        }
        ;

    primary_expression 
        : Ids { 
            cout << "primary expression" << endl;
            $$ = $1;
        }
        | LITERAL_INT { 
            cout << yyval.intNumber << endl; 
            $$ = makenode(to_string(yyval.intNumber));
        }
        | LITERAL_FLOAT {
            cout << yyval.fltNumber << endl;
            $$ = makenode(to_string(yyval.fltNumber));
         }
        | STRING { 
            cout << "string" << endl;
            // add \ to string start and end
            $$ = makenode($1);
        }
        | BYTESTRING { 
            cout << "byte string" << endl;
            $$ = makenode($1);
        }
        | KEY_TRU {
            cout << "true" << endl;
            $$ = makenode("True");
         }
        | KEY_FALS {
            cout << "false" << endl;
            $$ = makenode("False");
         }
        | KEY_NONE { 
            cout << "none" << endl;
            $$ = makenode("None");
        }
        | funccall { 
            cout << "function call" << endl;
            $$ = $1;
        }
        | DELIM_LPAR expression DELIM_RPAR { 
            int uid = makenode("()");
            addChild(uid, $2);
            $$ = uid;
        }
        | DELIM_LBRACKET List_expression DELIM_RBRACKET {
            int uid = makenode("[]");
            addChild(uid, $2);
            $$ = uid;
        }
        ;



    /* Function Call */
    funccall :
        Names DELIM_LPAR arguments DELIM_RPAR {
            int uid = makenode("atomic_expr");
            addChild(uid, $1);
            int child = makenode("()");
            addChild(uid, child);
            addChild(child, $3);
            $$ = uid;
        }
        | IDENTIFIER DELIM_DOT funccall { 
            int uid = makenode("atomic_expr");
            addChild(uid, makenode($1));
            int dot = makenode(".");
            addChild(uid, dot);
            addChild(dot, $3);
            $$ = uid;
        }
        | RES_ID_SELF DELIM_DOT funccall {
            int uid = makenode("atomic_expr");
            addChild(uid, makenode("self"));
            int dot = makenode(".");
            addChild(uid, dot);
            addChild(dot, $3);
            $$ = uid;
         }

        ;
    
    arguments :
        expression { 
            cout << "arguments" << endl;
            $$ = $1;
        }
        | expression DELIM_COMMA arguments {
            cout << "arguments" << endl;
            int uid = makenode(",");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | %empty  {
            $$ = -1;
        }
        ;



    /* COMPOUND STATEMENT */

    compoundstatement : 
        ifstatement  {
            cout << "compound statement" << endl;
            $$=$1;
        }
        | whilestatement  { 
            cout << "compound statement" << endl;
            $$ = $1;
        }
        | forstatement  { 
            cout << "compound statement" << endl;
            $$ = $1;
        }
        | funcdef  { 
            cout << "compound statement" << endl;
            $$ = $1;
        }
        | classdef  { 
            cout << "compound statement" << endl;
            $$ = $1;
        }
        ;

    /* If Statement */
    
    ifstatement : 
        KEY_IF expression DELIM_COLON Suite elifblocks elseblock {
            cout << "if statement" << endl;
            int uid = makenode("if");
            addChild(uid, $2);
            addChild(uid, makenode(":"));
            addChild(uid, $4);
            addChild(uid, $5);
            addChild(uid, $6);
            $$ = uid;

        }
        | KEY_IF expression DELIM_COLON Suite elifblocks { 
            cout << "if statement" << endl;
            int uid = makenode("if");
            addChild(uid, $2);
            addChild(uid, makenode(":"));
            addChild(uid, $4);
            addChild(uid, $5);
            $$ = uid;
        }
        | KEY_IF expression DELIM_COLON Suite elseblock { 
            cout << "if statement" << endl;
            int uid = makenode("if");
            addChild(uid, $2);
            addChild(uid, makenode(":"));
            addChild(uid, $4);
            addChild(uid, $5);
            $$ = uid;
        }
        | KEY_IF expression DELIM_COLON Suite { 
            cout << "if statement4" << endl;
            int uid = makenode("if");
            addChild(uid, $2);
            addChild(uid, makenode(":"));
            addChild(uid, $4);
            $$ = uid;

        }

    elifblocks : 
        elifblock            { 
            cout << "elifblocks" << endl;
            $$ = $1;
        }
        | elifblocks elifblock   {
            cout << "elifblocks" << endl;
            int uid = makenode("elif");
            addChild(uid, $1);
            addChild(uid, $2);
            $$ = uid;
        }
        
        ;

    elifblock : 
        KEY_ELIF expression DELIM_COLON Suite  {
            cout << "elifblock" << endl;
            int uid = makenode("elif");
            addChild(uid, $2);
            addChild(uid, makenode(":"));
            addChild(uid, $4);
            $$ = uid;
         }
        ;

    elseblock :
        KEY_ELSE DELIM_COLON Suite  { 
            cout << "elseblock" << endl;
            int uid = makenode("else");
            addChild(uid, makenode(":"));
            addChild(uid, $3);
            $$ = uid;
        }
        
        ;


    /* While Statement */
    whilestatement :
        KEY_WHILE expression DELIM_COLON Suite elseblock  {
            cout << "while statement" << endl;
            int uid = makenode("while");
            addChild(uid, $2);
            addChild(uid, makenode(":"));
            addChild(uid, $4);
            addChild(uid, $5);
            $$ = uid;
         }
        | KEY_WHILE expression DELIM_COLON Suite  { 
            cout << "while statement" << endl;
            int uid = makenode("while");
            addChild(uid, $2);
            addChild(uid, makenode(":"));
            addChild(uid, $4);
            $$ = uid;
        }
        ;


    /* For Statement */

    forstatement :
        KEY_FOR for_expression DELIM_COLON Suite elseblock  {
            cout << "for statement" << endl;
            int uid = makenode("for");
            addChild(uid, $2);
            addChild(uid, makenode(":"));
            addChild(uid, $4);
            addChild(uid, $5);
            $$ = uid;
         }
        | KEY_FOR for_expression DELIM_COLON Suite  {
            cout << "for statement" << endl;
            int uid = makenode("for");
            addChild(uid, $2);
            addChild(uid, makenode(":"));
            addChild(uid, $4);
            $$ = uid;
         }
        ;

    for_expression :
        Names KEY_IN ForList    { 
            cout << "for expression" << endl;
            int uid = makenode("in");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid; 
        }
        
        ;

    ForList :
        funccall   {
            cout << "for list" << endl;
            $$ = $1;
         }
        | Ids  {
            cout << "for list" << endl;
            $$ = $1;
         }
        | DELIM_LBRACKET List_expression DELIM_RBRACKET {
            cout << "for list" << endl;
            int uid = makenode("[]");
            addChild(uid, $2);
            $$ = uid;
        
        }
    


    /* Function Definition */


    funcdef :
        KEY_DEF Names DELIM_LPAR params DELIM_RPAR DELIM_ARROW Return_Type DELIM_COLON Suite  { 
            cout << "function definition" << endl;
            int uid = makenode("def");
            addChild(uid, $2);
            int PARs = makenode("()");
            addChild(PARs, $4);
            addChild(uid, PARs);
            addChild(uid, $7);
            addChild(uid, makenode(":"));
            addChild(uid, $9);
            $$ = uid;
        }
        | KEY_DEF Names DELIM_LPAR params DELIM_RPAR DELIM_COLON Suite  { 
            cout << "function definition" << endl;
            int uid = makenode("def");
            addChild(uid, $2);
            int PARs = makenode("()");
            addChild(PARs, $4);
            addChild(uid, PARs);
            addChild(uid, makenode(":"));
            addChild(uid, $7);
            $$ = uid;
        }
        
        ;


    params: 
        Variable_Declaration  {
            cout << "params" << endl;
            $$ = $1;
        }
        | params DELIM_COMMA Variable_Declaration {
            cout << "params" << endl;
            int uid = makenode(",");
            addChild(uid, $1);
            addChild(uid, $3);
            $$ = uid;
        }
        | RES_ID_SELF {
            cout << "params" << endl;
            $$ = makenode("self");
        }
        | %empty {
            cout << "params" << endl;
            $$ = -1;
        }
        ;  
    Return_Type : 
        Primitive_Type { 
            cout << "return type" << endl;
            $$ = $1;
        }
        /* | List_Type { cout << "return type" << endl;} */
        | KEY_NONE { 
            cout << "return type" << endl;
            $$ = makenode("None");
        }

    Suite : 
        simplestatement NEWLINE { 
            cout << "suite" << endl;
            $$ = $1;
        }
        | NEWLINE INDENT statements DEDENT { 
            cout << "--------------" << endl;
            $$ = $3;
        }
        ; 

    

    classdef :
        KEY_CLASS Names DELIM_COLON Suite    { 
            cout << "class definition" << endl;
            int uid = makenode("class");
            addChild(uid, $2);
            addChild(uid, makenode(":"));
            addChild(uid, $4);
            $$ = uid;
        }
        | KEY_CLASS Names DELIM_LPAR arguments DELIM_RPAR DELIM_COLON Suite  { 
            cout << "class definition" << endl;
            int uid = makenode("class");
            addChild(uid, $2);
            int PARs = makenode("()");
            addChild(PARs, $4);
            addChild(uid, PARs);
            addChild(uid, makenode(":"));
            addChild(uid, $7);
            $$ = uid;
        }
        ;


    Names:
        IDENTIFIER { 
            $$ = makenode($1);
        }
        | RES_ID_SELF { 
            $$ = makenode("self");
        }
        | RES_ID_INIT { 
            $$ = makenode("__init__");
        }
        | RES_ID_MAIN { 
            $$ = makenode("main");
        }
        ;
    

    





  


    /*  */

        
%%

int main(int argc, char **argv){
    if(argc > 1){
        /* printf("File name: %s\n", argv[1]); */
        FILE *fp = fopen(argv[1], "r");
        if(fp){
            yyin = fp;
            yyparse();
            fclose(fp);
        }
        else{

            printf("Error: File not found\n");
        }
    }
    else   {
        
         FILE *fp = fopen("input.py", "r");
         if(fp) {
                yyin = fp;
         }
         yyparse();
         fclose(fp);
    }
    writeDotFile(tree, "tree.dot");
    return 0;
}

void yyerror(const char *message)
{
    std::cerr << "Error at line " << yylineno << ": " << message << std::endl;
    std::cerr << "Token: " << yytext << std::endl;
    exit(EXIT_FAILURE); // Terminate the program after encountering an error
}