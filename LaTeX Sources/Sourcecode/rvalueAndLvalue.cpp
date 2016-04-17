string st = "Hello from an Lvalue";
foo(st);

foo(string("Hello from an Rvalue"));

void foo(string&& st) {
 ...   
}

string st = "Hello from an Lvalue";
foo(move(st));