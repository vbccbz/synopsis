GCC 
	utf8
	Настройка переменных сред для возможности ввода gcc без полного пути:
	Переменные среды, создать PATH с значением D:\GDrive\books\C\MinGW\bin\

	Настройка директории по-умолчанию при запуске консоли:
	[HKEY_CURRENT_USER\Software\Microsoft\Command Processor] "Autorun"="cd /d D:\GDrive\books\С\MinGW\CUBEC" 
	/d нужна при смене диска

	Директории gcc:
	MinGW\libexec\mingw-get\guimain.exe
	MinGW\bin\gcc.exe

SUBLIME 
	settings:
	{
		"fallback_encoding": "Cyrillic (Windows 1251)",
		"auto_complete" : false,
		"tab_completion" : false,
		"update_check": false,
		"word_wrap": "true",
		"wrap_width": 80,
		"tab_size": 2,
		"line_numbers": true,
		"animation_enabled": false,
		"color_scheme": "Packages/Color Scheme - Default/Zenburnesque.tmTheme",
		"font_size": 12,
		"scroll_speed": 0.0,
		"tree_animation_enabled": false,
		"update_check": false,
		"show_errors_inline": true,
		"always_show_minimap_viewport": true,
	  "draw_minimap_border": true
	}
	keyBinding:
	[
		
		{ "keys": ["alt+j"], "command": "move", "args": {"by": "characters", "forward": false} },
		{ "keys": ["alt+l"], "command": "move", "args": {"by": "characters", "forward": true} },
		{ "keys": ["alt+i"], "command": "move", "args": {"by": "lines", "forward": false} },
		{ "keys": ["alt+k"], "command": "move", "args": {"by": "lines", "forward": true} },
		
		{ "keys": ["shift+alt+j"], "command": "move", "args": {"by": "characters", "forward": false, "extend": true} },
		{ "keys": ["shift+alt+l"], "command": "move", "args": {"by": "characters", "forward": true, "extend": true} },
		{ "keys": ["shift+alt+i"], "command": "move", "args": {"by": "lines", "forward": false, "extend": true} },
		{ "keys": ["shift+alt+k"], "command": "move", "args": {"by": "lines", "forward": true, "extend": true} },

		{ "keys": ["ctrl+shift+alt+i"], "command": "swap_line_up" },
		{ "keys": ["ctrl+shift+alt+k"], "command": "swap_line_down" },

		{ "keys": ["ctrl+shift+l"], "command": "expand_selection", "args": {"to": "line"} },
		{ "keys": ["ctrl+shift+k"], "command": "run_macro_file", "args": {"file": "res://Packages/Default/Delete Line.sublime-macro"} },

		{ "keys": ["alt+p"], "command": "move", "args": {"by": "pages", "forward": false} },
		{ "keys": ["alt+;"], "command": "move", "args": {"by": "pages", "forward": true} },


		{ "keys": ["ctrl+shift+i"], "command": "show_panel" },
		{ 
			"keys": ["ctrl+tab"], 
			"command": "next_view"
		},
		{ 
			"keys": ["ctrl+shift+tab"], 
			"command": "prev_view"
		},
		{ 
			"keys": ["ctrl+l"], 
			"command": "expand_selection", 
			"args": {"to": "line"} ,
			// "command": "move_to", 
			//"args": {"to": "eol", "extend": true} 
		},
		{	// Move out of common paired characters () and [] with `Tab`
			"keys": ["tab"],
			"command": "move",
			"args": {"by": "characters", "forward": true},
			"context": [
				// Check if next char matches (followed by anything)
				{ "key": "following_text", "operator": "regex_match", "operand": "(:?`|\\)|\\]|\\}).*", "match_all": true },
				// ...and that there is a paid character before it on the same
				// line. This lets you `tab` to Indent at lines with single ]s
				// still, like in a JSOn file
				{ "key": "preceding_text", "operator": "regex_contains", "operand": "(:?`|\\(|\\[|\\{)", "match_all": true }
			]
		},
		{	// Move out of single and double quotes with `Tab`
			"keys": ["tab"],
			"command": "move",
			"args": {"by": "characters", "forward": true},
			"context": [
				{ "key": "following_text", "operator": "regex_match", "operand": "(?:\"|').*", "match_all": true },

				{ "key": "preceding_text", "operator": "regex_contains", "operand": "(?:\"|')", "match_all": true }
			]
		},
		
	]


	Ctr+K,B скрыть панель папки слева, если она была. 

	Mark    Description Windows
	' ' Straight single apostrophe  alt+39 
	" " Straight double quote               alt+34   
	‘   Opening single apostrophe           alt+0145
	’   Closing single apostrophe           alt+0146
	“   Opening double quote                    alt+0147
	”   Closing double quote                    alt+0148

	Экранирование символов — механизм, имеющийся в текстовых языках и протоколах. Он служит, чтобы символы, которые считаются служебными и имеют особое значение, этого значения лишить и объявить «просто символами». 
	Нам нужно двойное экранирование: для ОС (строка с пробелами закавычивается) и для Си (перед кавычкой слэш).
	system("gcc \"C:/Folder/My Folder/example.c\" ");
	Точно так же экранируется и обратный слэш, если вдруг потребуется.
	system("gcc \"C:\\Folder\\My Folder\\example.c\" " );

	cd D:\books
	gcc C:\Cex\test.c -o C:\Cex\test.exe

	Настройка для создания исполняемого файла из саблайма.
	tools>build system
	{
		"cmd": ["C:/MinGW/bin/gcc.exe", "-std=c99", "-Wall", "${file}", "-o", "${file_base_name}.exe"],
		"file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
		"working_dir": "${file_path}",
		"selector": "source.c, source.c++",
		"encoding": "cp1252", //без этого, если в пути есть русский символ, то будет Decode error - output not utf-8...
		"shell": true,

		"variants":
		[
			{
				"name": "Run",
				"cmd": ["start", "cmd", "/k", "${file_path}/${file_base_name}.exe"],
				"shell": true
			}
		]
	}

	#include <stdlib.h> 
	system("gcc \"C:/GD/books/Coding/MinGW/CUBEC/test.c\" ");
	system("a");

	Настройка для создания исполняемого файла из саблайма V2.
	tools>build system
	{
    "cmd": 
    [
        "g++", "-g", "-std=gnu++03", "-Wall", "-fno-elide-constructors", "-S", "${file}", "-o", "${file_base_name}.s",
        "&&",
        "g++", "-g", "-std=gnu++03", "-Wall", "-fno-elide-constructors", "${file_base_name}.s", "-o", "${file_base_name}.exe",
    ],
    "file_regex": 
        "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": 
        "${file_path}",
    "selector": 
        "source.c, source.c++",
    "shell": 
        true,
    "variants": 
    [
        {
            "name": "Run",
            "cmd": ["start", "cmd", "/k", "${file_path}/${file_base_name}.exe"],
            "shell": true
        }
    ]
}

Введение. 
	
	Разбито на 7 абзацев.
	I now assert that at long last we have assembled a piece of hardware that we can honestly call a computer. To be sure, it is a primitive computer, but it is a computer nonetheless. 
	What makes the difference is the conditional jump. Controlled repetition or looping is what separates computers from calculators.//Petzold 
	The C language facilitates a structured and disciplined approach to computer-program design. We then use the structured approach throughout the remainder of the C portion of the text.//Deitel

	//1  
		#include <stdio.h>
	Lines beginning with # are processed by the preprocessor before compilation. 
	This is a directive to the C preprocessor. It tells the preprocessor to include the contents of the standard input/output header (<stdio.h>) in the program. This header contains information used by the compiler when compiling calls to standard input/output library functions such as printf. We explain the contents of headers in more detail in Chapter 5 and 13.

	//2  
		int main ( void )//int main () 
		{
			statement;
		}
	The parentheses () (or round brackets?) after main indicate that main is a program building block called a function. C programs contain one or more functions, one of which must be main. The main function is a part of every C program. Every program in C begins executing at the function main. 
	A left brace { begins the body of every function. A corresponding right brace } ends each function. This pair of curly braces (or curly brackets?) and the portion of the program between the braces is called a block. The block is an important program unit in C. 
	Functions can return information. The keyword int to the left of main indicates that main “returns” an integer (whole-number) value. We’ll explain what it means for a function to “return a value” when we demonstrate how to create your own functions in Chapter 5. 
	Functions can receive information when they’re called upon to execute. The void in parentheses here means that main does not receive any information. In Chapter 14, we’ll show an example of main receiving information. 

	//3   
		printf( "Welcome \\ to C!\n" );
	An Output Statement. Line instructs the computer to perform an action, namely to print on the screen the string of characters marked by the quotation marks "". 
	The entire line, including the printf function (the “f” stands for “formatted”), its argument within the parentheses () and the semicolon ; , is called a statement (инструкция). Every statement must end with statement terminator a semicolon ; . Parameters and arguments are different concepts.

	
	Символы (characters или symbols) это:
		буква (литера, letter; A–Z and a–z), 
		знак (sign или special symbol; e.g., $, @, %, &, *, (, ), –, +, quotation mark, :, ? and / ),
		цифра (digit). 
	
	c99. The categories of tokens are: keywords, identifiers, constants, string literals, and punctuators.
	cpp. There are five kinds of tokens: identifiers, keywords, literals, operators (operator-or-punctuator), and other separators.

	literal constant (literal, литерал, constant, константа???) - это зафискированное значение одного из базовых типов (ну, не только) в исходном коде: 
		5 целочисленный (integer, int) 
		3.14159 численный (numeric, нет - double)
		'A' символьный (character, char)
		"cat" строковый (string, char*) 
	Не путать с const.

	symbolic constants
		#define PI 3.14159 
	replaces all subsequent occurrences of the symbolic constant PI with the numeric constant 3.14159. 
	Еще упоминается символическая целочисленная константа (symbolic integer constant SIZE, EOF), иногда без уточнения о целочисленности.
		Еще An enumeration is a set of named integer constants.

	Последовательность символов, заканчивающаяся \0, называется строкой (string). A string is sometimes called a character string, a message or a literal. Строка является частным случаем массива (array). 

	The backslash (\) is called an escape character. When encountering a backslash in a string, the compiler looks ahead at the next character and combines it with the backslash to form an escape sequence (в некотороых переводах esс-код). The escape sequence \n means newline. 
	A characters and a whitespace characters, their an escape sequences, and ASCII :
			null character  '\0' 0
			alert           '\a' 7
			horizontal tab  '\t' 9
			newline         '\n' 10
			form feed       '\f' 12
			carriage return '\r' 13
			vertical tab    '\v' 17
			space           ' '  32
			backslash       '\\' 92
			double quote    '\"' 34

	Printf causes the computer to perform an action. As any program executes, it performs a variety (множество) of actions and makes decisions. Executable statements either (либо) perform actions (calculations, input or output of data, etc) or make decisions (if, while, etc). 

	The Linker and Executables. Standard library functions like printf and scanf are not part of the C programming language. Сompiler cannot find a spelling error in printf or scanf. When the compiler compiles a printf statement, it merely provides space in the object program for a “call” to the library function (e.g printf). But the compiler does not know where the library functions are — the linker does. When the linker runs, it locates the library functions and inserts the proper calls (соответствующие вызовы) to these library functions in the object program (причем, вставляет он уже обжекнутые куски кода). Now the object program is complete and ready to be executed. For this reason, the linked program is called an executable. If the function name is misspelled, the linker will spot the error, because it will not be able to match the name in the C program with the name of any known function in the libraries.

	//4  
		int integer1, integer2;
		int sum; 
	This line are definitions (определения). 
	The names integer1, integer2 and sum are the names of variables (переменных). Variables is the locations in memory where values can be stored for use by a program. Variable names such as integer1 and sum actually correspond to locations in the computer’s memory. Variable is a named location in memory that is used to hold a value that can be modified by the program. 
	These definitions specify (задают, определяют) that variables integer1, integer2 and sum are of type int, which means that they’ll hold integer values, i.e., whole numbers such as 7, –11, etc. Every variable has a name, a type and a value. All variables must be defined with a name and a data type before they can be used in a program. 
	Definitions are not executable statements—they’re simply messages to the compiler (стр 72). 
	For readers using the Microsoft Visual C++ compiler, note that we’re placing our variable definitions immediately after the left brace { that begins the body of main. The C standard allows you to place each variable definition anywhere in main before that variable’s first use in the code. Some compilers, such as GNU gcc, have implemented this capability. We’ll address this issue in more depth in later chapters. Recall that the Microsoft Visual C++ compiler requires variable definitions to be placed after the left brace { of a function and before any executable statements. Therefore, in the program in Fig. 2.5, inserting the definition of integer1 after the first printf would cause a syntax error in Visual C++. 
	Вдобавок объявления могут быть внутри выделенных блоков, тогда они будут скрыты от остальных областей, см. области действия (Scope). 
	A variable name in C is any valid identifier (идентификатор). An identifier is a series of characters consisting of letters, digits and underscores (_) that does not begin with a digit. C is case sensitive — uppercase and lowercase letters are different in C, so a1 and A1 are different identifiers. The first letter of an identifier used as a simple variable name should be a lowercase letter. Later in the text we’ll assign special significance to identifiers that begin with a capital letter and to identifiers that use all capital letters. 
	 
	//5  
		scanf ("%d", &integer1);
		scanf ("%d", &integer2);
	This statement uses scanf (the “f” stands for “formatted”) to obtain a value from the user. The function reads from the standard input, which is usually the keyboard. 
	This scanf has two arguments: "%d" and &integer1. 
	The first, the format control string (строка управляющая форматом) "%d". It indicates the type of data that should be entered by the user. The %d conversion specifier (спецификатор преобразования) indicates that the data should be an integer. The % in this context is treated (рассматривается) by scanf (and printf as we’ll see) as a special character that begins a conversion specifier. The letter d stands for “decimal integer”. 
	The second argument &integer1 of scanf begins with an ampersand & (address operator) followed by the variable name (& (адрес оператор) за которым следует имя переменной). The &, when combined with the variable name integer1, tells scanf the location (or address) in memory at which the variable integer1 is stored. The computer then stores the value that the user enters for integer1 at that location. 
	Some exceptions to this rule are discussed in Chapters 6 and 7. The use of the ampersand will become clear after we study pointers in Chapter 7. 
	Forgetting to precede (предварить) a variable in a scanf statement with an ampersand when that variable should, in fact, be preceded by an ampersand this causes a “segmentation fault” or “access violation.” The precise cause of this error will be explained in Chapter 7.

	//6
		sum = integer1 + integer2;  
	This is assignment (присваивания) statement calculates the total of variables integer1 and integer2 and assigns the result to variable sum using the assignment operator =. Most calculations are performed in assignments. The = operator and the + operator are called binary operators because each has two operands. The + operator’s two operands are integer1 and integer2. The = operator’s two operands are sum and the value of the expression (выражение) integer1 + integer2.
	scanf требует именно адрес для помещения чего либо в ячейку. sum = integer1 + integer2 является "обратиться по адресам aabbcc11 и aabbcc44, сложить, поместить по адресу aabbccdd". sum = &integer1 + &integer2 является "не обращаться, а взять сами адреса aabbcc11 и aabbcc44, сложить, поместить по адресу aabbccdd".

	//7 
		printf( "Sum is %d\n", sum ); 
	Line calls function printf to print the literal Sum is followed by the numerical value of variable sum on the screen. This printf has two arguments, "Sum is %d\n" and sum. The first argument "Sum is %d\n" is the format control string. It contains some literal characters (or literal) Sum is to be displayed, and it contains the conversion specifier %d indicating that an integer will be printed. The second argument sum specifies (задает) the value to be printed. 
	Secure print:
		puts( "Welcome to C!" );
		printf( "%s", "Welcome " );//a string with printf.

	Теперь в общем.
		
		mov @A, r0
		mov (r0), r1
		mov @B, r0
		add (r0), r1
		mov @sum, r0
		mov r1, (r0)
		stop
		A:
		data 1
		B:
		data 2
		sum:
		data 0

		0000    01D0    MOV 14, RO
		0002    0014            
		0004    0141    MOV (R0),   Rl
		0006    01DO    MOV 16, R0      
		0008    0016  
		ОООА    0241    ADD (R0), R1
		ОООС    01D0    MOV 18, R0
		ОООЕ    0018    
		0010    0114    MOV R1, (R0)
		0012    FFFF    STOP        
		0014    0001    
		0016    0002    
		0018    0000    

	Датасаенс и информатика > логика и языки высокого уровня > выражения. На языке асемблера каждую часть от х = 2+3-5*6 нужно описать вручную, выделить место в памяти, назвать это место меткой "х", затем поочередно сложить, затем сохранить результат обратно в память. Си имеет свои абстракции.
	https://en.wikipedia.org/wiki/Expression_(computer_science) :
	An expression in a programming language is a combination of one or more constants, variables, operators, and functions that the programming language interprets (according to its particular rules of precedence (приоритет, приоритетность, старшинство, предшествование) and of association (ассоциативность) ) and computes (вычисляет) to produce (производства) ("to return", in a stateful environment) another value. This process, as for mathematical expressions, is called evaluation.
	https://en.wikipedia.org/wiki/Statement_(computer_science) :
	In computer programming, a statement is a syntactic unit of an imperative programming language that expresses (выражает) some action to be carried out (которые необходимо выполнить). A program written in such (таком) a language is formed (сформирована чем) by a sequence of one or more statements. A statement may have internal components (e.g. например, expressions). Many imperative languages (e.g. C) make a distinction (делают различие) between statements and definitions, with (причем) a statement only containing executable code and a definition instantiating an identifier (определение, создающее экземпляр идентификатора), while (тогда как) an expression evaluates (оценивается) to a value only. A distinction (различие) can also be made between simple and compound (составная) statements; the latter may contain statements as components. Simple statements: a = a + b; return z; Compound statements: {} блок, if, for. In most languages, statements contrast with expressions, in that statements do not return results and are executed solely for their side effects, while (когда как) expressions always return a result and often do not have side effects at all. This distinction (различие) is frequently observed in wording (в формулировках) : a statement is executed, while an expression is evaluated. In purely (чисто) functional programming, there are no statements; everything is an expression.
	C how to program:
	Pseudocode consists only of action statements—those that are executed when the program has been converted from pseudocode to C and is run in C. Definitions are not executable statements—they’re simply messages to the compiler. For example, the definition tells the compiler the type of variable i and instructs the compiler to reserve space in memory for the variable. But this definition does not cause any action—such as input, output, a calculation or a comparison—to occur when the program is executed. 
	Unknown:
	An expression is a sequence of operators. Statements are fragments of the C program that are executed in sequence (в последовательности или последовательно?). The body of any function is a compound statement which in turn is a sequence of statements and declarations (объявлений, описаний, деклараций).
	Schildt:
	Operators, constants, functions, and variables are the constituents of expressions. 

	Quoting from Eric Lippert`s Blog:
		The evaluation of an arithmetical expression is controlled by three sets of rules: precedence rules, associativity rules, and order rules.
		Precedence rules (order of evaluation of the operators, rules of operator precedence) describe how an underparenthesized expression should be parenthesized when the expression mixes different kinds of operators.
		Associativity rules (associativity) describe how an underparenthesized expression should be parenthesized when the expression has a bunch of the same kind of operator.
		Order of evaluation rules (order of evaluation of operands) describe the order in which each operand in an expression is evaluated.

	The rules of operator precedence specify the order C uses to evaluate expressions. The associativity of the operators specifies whether (будут ли) they evaluate from left to right or from right to left. The circled numbers indicate the order in which C evaluates the operators: 
		z = p * r % q + w / x - y;
		//6   1   2   4   3   5
		while ( ( grade = getchar( ) ) != EOF ) 
		{
			;
		}
	In the while header the parenthesized assignment (grade = getchar()) executes first. The getchar function (from <stdio.h>) reads one character from the keyboard and stores that character in the integer variable grade. Assignments as a whole actually have a value (присваивание само по себе имеет значение). This value is assigned to the variable on the left side of the =. The value of the assignment expression grade = getchar() is the character that’s returned by getchar and assigned to the variable grade. In the program, the value of the assignment grade = getchar() is compared with the value of EOF (a symbol whose acronym stands for “end of file”).
		a = b = c = 0;
	The fact that assignments have values can be useful for setting several variables to the same value. For example, a = b = c = 0; first evaluates the assignment c = 0 (because the = operator associates from right to left). The variable b is then assigned the value of the assignment (переменной b присваивается значение выражениЯ) c = 0 (which is 0). Then, the variable a is assigned the value of the assignment b = (c = 0) (which is also 0).
	Any expression in C that produces a value can be used in the decision portion of any control statement. 
		if ( payCode == 4 )
			printf( "%s", "You get a bonus!" );
		if ( payCode = 4 )//всегда истинно, пока присваивается ненулеваое значение.
			printf( "%s", "You get a bonus!" );
		for (; *s1 = *s2; s1++, s2++) {//истинно, пока результат присваивания больше нуля.
			;
		}

Order of Evaluation of Operands. 
	???
		unsigned long long int fibonacci ( unsigned int n ) 
		{
			if ( 0 == n || 1 == n ) 
			{
				return n;
			}	
			else
			{
				return fibonacci( n - 1 ) + fibonacci( n - 2 );
			} 
		} 
	This figure raises some interesting issues about the order in which C compilers will evaluate the operands of operators. This is a different issue from the order in which operators are applied to their operands, namely the order dictated by the rules of operator precedence.
	Figure 5.20 shows that while evaluating fibonacci(3), two recursive calls will be made, namely fibonacci(2) and fibonacci(1). But in what order will these calls be made? You might simply assume the operands will be evaluated left to right. For optimization reasons, C does not specify the order in which the operands of most operators (including +) are to be evaluated. Therefore, you should make no assumption about the order in which these calls will execute. The calls could in fact execute fibonacci(2) first and then fibonacci(1), or the calls could execute in the reverse order, fibonacci(1) then fibonacci(2).
	In this and most other programs, the final result would be the same. But in some programs the evaluation of an operand may have side effects that could affect the final result of the expression. 
	For example, the expression
		x = f1() + f2();
	does not ensure that f1( ) will be called before f2( ).
	C specifies the order of evaluation of the operands of only four operators— namely &&, ||, the comma (,) operator and ?:. The first three of these are binary operators whose operands are guaranteed to be evaluated left to right. Именно поэтому лучше наиболее вероятную истину ставить слева от ||, а наиболее вероятную ложь слева от &&, с запятой и тренарным смотри примеры ниже. [Note: The commas used to separate the arguments in a function call are not comma operators.] The last operator is C’s only ternary operator. Its leftmost operand is always evaluated first; if the leftmost operand evaluates to nonzero, the middle operand is evaluated next and the last operand is ignored; if the leftmost operand evaluates to zero, the third operand is evaluated next and the middle operand is ignored.

	Как я понимаю. Операторы постфикса и префикса не имеют порядка оценки операндов. Следовательно, поведение выражения не определено, если внутри находится несколько постфиксов или префиксов. 
		int a = 2;
		a = ++a * ( ++a + 5);
	Such statements will invoke undefined behavior if there is no guarantee of evaluation order of operands of an operator. But this is not true in context of java programming language. It has well defined behavior in java (as well as in C#). The Java Language Specification states that 15.7. Evaluation Order. The Java programming language guarantees that the operands of operators appear to be evaluated in a specific evaluation order, namely, from left to right.
	Еще вопрос. Round brackets (parentheses) не являются оператором в контексте выражения. Parentheses just express grouping, they do not express ordering of evaluation. И в С, и в джаве? Странный какой-то вопрос. В принципе, скобки могли бы и быть оператором, в принципе пофигу. Функш кол оператором они становятся только если рядом стоит имя функции. А вот в выражениях - непонятно.

Operators
	Символы * & [] () и , оцениваются в зависимости от контекста. In C, there are precedence relationships in declarations. Не путать смысл в объявлениях и смысл в выражениях.
	Operator precedence and associativity.

		Operators                           Associativity       Type    
		//My comment
		() () [] . ->                       left to right       parentheses     
		//() Operators in expressions contained within pairs of parentheses are evaluated first; func() function call operator; [] (square brackets) the brackets used to enclose the subscript of an array, the array subscripting operator; aCard.face the structure member operator; cardPtr->face the structure pointer operator.
		++(postfix) --(postfix)             right to left 
		//type длинный: postfix, unary, highest; на стр 281 имеют одинаковую приоритетность со строчкой выше, так же не понятно,почему постфикс имеет приоритет выше префикса.
		+ - ! ~ ++ -- (type) & * sizeof     right to left       unary           
		//unary versions (+5,-7), !(grade != sum),  ~ bitwise complement, ++a, --b, cast operator a(float), address operator, indirection operator, sizeof operator.
		* / %                               left to right       multiplicative  
		//binary
		+ - << >>                           left to right       additive        
		//binary
		< > <= >=                           left to right       relational
		//
		== !=                               left to right       equality        
		//The equality operators have a lower level of precedence than the relational operators and they also associate left to right (см ниже, в if и в Logical Operators).
		& | ^                               left to right       bitwises
		//binary, bitwises AND OR XOR 
		&& ||                               left to right       logical
		//binary, logical AND OR
		?:                                  right to left       conditional     
		//ternary
		= += -= *= /= %=                    right to left       assignment      
		&= |= ^= <<= >>=
		//binary
		,                                   left to right       comma           
		//см ниже пример.

		https://en.wikipedia.org/wiki/Order_of_operations
		https://en.wikipedia.org/wiki/Operator_associativity

		(стр 52, 136, 218, 281) Понятнее было бы associativity and operator precedence/order of operations (operator precedence понятнее звучит), потому что сначала нужно разобраться почему 7 - 4 + 2 = 5, а не 1; и только потом разбираться почему * старше +. 
			В алгебре 7 - 4 + 2 = 7 + (- 4) + 2.

		7 - 4  + 2 из-за левоассоциативности распознается как (7 - 4) + 2 = 5 ; если бы эти операции были правоассоциативными, то 7 - (4 + 2) = 1.
		8 / 16 / 2 распознается как 1/2 / 2 = 1/4   , а не 8 / 8 = 1
		4/8/2/3 = 4 / (8*2*3)
		4/8/2/3 в реале нужно следить за associativity , а если в реале в виде дробей 4 * 1/8 * 1/2 * 1/3 то необязательно (в си везде следить нужно).
		3 < 2 < 1 даст 1. А в питоне wiki: a < b < c  распознается как ( a < b ) && ( b < c ). 
		a = 2    b = 1    c = 3
		a == b          0
		a != b          1
		b <= c          1
		a == b <= c     0
		(a == b) <= c   1
		a != b <= c     1
		a = b <= c      0
		a = b; и b = a; разные инструкции.
		a = b = c = 0 распознается как a = (b = (c = 0)) в том числе и потому, что Assignments as a whole actually have a value. То есть здесь суть не только в ассоциативности.
		Statement c = c + 3; can be abbreviated (сокращена) with the addition assignment operator += as c += 3; Это компилируется быстрее.

		C also provides the unary increment operator ++ and the unary decrement operator --.
			a = 5;
			printf("%d\n", ++a);//6 ; преинкремент, увеличивает на 1, использует новое значение. Преинкремент работает быстрее.
			printf("%d\n", a    );//6 
			a = 5;
			printf("%d\n", a++);//5 ; постинкремент, использует значение, потом увеличивает на 1.
			printf("%d\n", a    );//6
		C generally does not specify the order in which an operator’s operands will be evaluated (although we’ll see exceptions to this for a few operators in Chapter 4). Therefore you should use increment or decrement operators only in statements in which one variable is incremented or decremented by itself (использовать в отдельных инструкциях). 

		The commas used to separate the arguments in a function call are not comma operators. The comma operator guarantees that lists of expressions evaluate from left to right. The value of the entire expression is that of the rightmost expression. The value of the rightmost expression becomes the value of the entire expression. Смотри пример ниже и в for:
			int j = 1;
			j = (j++, j+333, 4+j);//2, 2+333, 4+2; без скобок будет 1.
			printf ("%d\n", j );//6

		lvalues and rvalues. 
		Variable names are said to be lvalues (for “left values”) because they can be used on the left side of an assignment operator.
			sum = 666;
		Constants are said to be rvalues (for “right values”) because they can be used on only the right side of an assignment operator.
			sum = 666;
		lvalues can also be used as rvalues, but not vice versa. 
			a = b; b = a; a = 666; 666 = a ошибка.
			x == 7 равносильно 7 == x. 
		После if statement.
			day = a > 9 ? 100 : 200 ;
			day == 10 ? a = 1 : a = 0 ;// a = 0 lvalue required as left operand of assignment???
			day == 10 ? (a = 1) : (a = 0) ;//а так работает.    
			a = day == 10 ? 1 : 0 ;

Keywords
	???
		auto double int struct
		break else long switch
		case enum register typedef
		char extern return union
		const float short unsigned
		continue for signed void
		default goto sizeof volatile
		do if static while
	Keywords added in C99 standard
		_Bool _Complex _Imaginary inline restrict
	Keywords added in C11 draft standard
		_Alignas _Alignof _Atomic _Generic _Noreturn _Static_assert _Thread_local

	См. базовые типы данных языка C, спецификаторы типов (signed, unsigned, long, short). Есть некоторые вопросы с char. signed char и unsigned char, будет зависеть от ключей компиляции, вероятно. "abcd" - строка имеет тип char. Если передать адрес этой строки указателю с типом unsigned char или даже signed char - появится предупреждение.

data types
	Fig. 5.5 Arithmetic data types (and their conversion specifications, see 9.3 Formatting Output):
		data_type 
			минимальный размер
				printf_conversion_specification 
					scanf_conversion_specification
		Floating-point types (Вещественные типы)
							float         4  %f   %f 
							double        8  %f   %lf
		long			double        16 %Lf  %Lf
		Integer types (Целочисленные типы)
							char          1  %c   %c
		signed		char 
		unsigned	char 
				 			short         2  %hd  %hd
		unsigned	short            %hu  %hu
							int           4  %d   %d
		unsigned       int         %u   %u
							long int      4  %ld  %ld
		unsigned	long int         %lu  %lu
							long long int 8  %lld %lld
		unsigned	long long int    %llu %llu 

	Еще типы:
		#include <stdint.h>
		intN_t где N:8,16,32.
		uintN_t где N:8,16,32.

	Еще спецификации:
		%x
		%p

Suffixes for Integer and Floating-Point Literals
	C provides integer and floating-point suffixes for explicitly specifying the data types of integer and floating-point literal values. (The C standard refers to such literal values as constants). If an integer literal is not suffixed, its type is determined by the first type capable of storing a value of that size (first int, then long int, then unsigned long int, etc.). A floating-point literal that’s not suffixed is automatically of type double.
	The integer suffixes:
		unsigned int u U 
		long int l L
		long long int ll LL
		//9876543210llu unsigned long long int
	The floating-point suffixes: 
		float f F
		long double l L 
		//3.14159L long double - точка должна быть!
	Почему это важно (точно так же это работает при разыменовывании указателя в зависимости от знаковости типа указателя, signedness):
		//32767      32767       
		//32768     -32768
		//32769     -32767
		//32770     -32766
		for (unsigned short i = 32767; i > 0 && i < 32770 ; ++i)    {
			printf("%d\n", i);//32767 32768	32769
		}
		for (short i = 32767; i > 0 && i < 32770; ++i)  {
			printf("%d\n", i);//32767
		}

Явные и неявные преобразования.
	int A = 2; int B = 5; float C = 7; 
	printf("%d %d\n", A/B, B/A );//0 2 
	printf("%d %f\n", 3/2, 3/2 );//1 0.00000 из-за усечения; у вещественных свое устройство, %f не может работать с int.
	printf("%f\n", 3.0/2.0 );//1.500000, оба просто float сами по себе по умолчанию. 
	printf("%f %f\n", 3.0/2, A/C );//1.500000 0.285714, компилятор выполнит неявные преобразования (implicit conversion) 2 в 2.0 и int A во float (создается копия).
	printf("%f\n", (float) A/B );//0.50, произойдет явное преобразование (explicit conversion) int A во float, что потом неявно возведёт int B до float.
	printf("%f\n", 3/2*3.14 );//3.140000
	printf("%f\n", 2/3*3.14 );//0.000000.
	printf("%f\n", 3.0/2*3.14 );//4.710000
	printf("%f\n", 3/2.0*3.14 );//4.710000
		
	int p = 4; float g = 4.35;
	printf ("%d\n", p);//4
	printf ("%f\n", p);//-1.#QNAN0
	printf ("%d\n", g);//1610612736
	printf ("%f\n", g);//4.350000
	p = 4; 
	g = 4.35;
	p = g;
	printf ("%d\n", p);//4
	printf ("%f\n", p);//4.349998
	p = 4; 
	g = 4.35;
	g = p;
	printf ("%d\n", g);//0
	printf ("%f\n", g);//4.000000

sizeof Operator.
	size_t integral type (unsigned int or unsigned long int) returned by operator sizeof. Type size_t is defined in header <stddef.h>. sizeof выполняется на этапе компиляции, возвращает количество байтов объекта.
		char z = 'X';//
		printf ("%c\n", z);//X
		printf ("%d\n", sizeof( z )  );//1
		printf ("%d\n", sizeof(char) );//1
		printf ("%d\n", sizeof(int)  );//4
		printf ("%d\n", sizeof(3)    );//4
		printf ("%d\n", sizeof(3ll)  );//8
		printf ("%d\n", sizeof(3.14) );//8
		printf ("%d\n", sizeof('A')  );//4
		printf ("%d\n", sizeof("AB") );//3
		double real [ 22 ];//объялен массив.
		printf ("%d", sizeof( real ) / sizeof( real[ 0 ] ) );//количество элементов массива

Endianness (Порядок байтов)
	#include <stdio.h>
	#include <stdint.h>
	int main(void){
	uint16_t x = 1; /* 0x0001 or 00 01*/
	printf("%s\n", *((uint8_t *) &x) == 0 ? "big-endian" : "little-endian");
	return 0;
	}

Control structures. 
	A procedure for solving a problem in terms (в виде) of the actions to be executed, and the order in which these actions are to be executed is called an algorithm. Управляющие структуры (не путать со структурами данных) - это из датасаенс, общее понятие. В основе лежит отказ от goto и получение структурного программирования. В C эти структуры реализованы в виде инструкций. Суть в том, что бы любая структура подключалась к остальным как блок с одним входом и одним выходом. Это отлично видно в flowcharts. 
	All programs could be written in terms only three control structures: 
		The sequence structure is simple — unless directed otherwise (если не указано иное), the computer executes C statements one after the other in the order in which they’re written; 
		Selection Statements: if, if/else, switch; 
		Repetition Statements: while, for, do/while.

The if Statement, single-selection statement (с одиночным выбором).
	if ( /*condition*/ ) {
		statement;
	}
	Conditions in if statements are formed by using the equality operators and relational (отношения) operators. The relational operators all have the same level of precedence and associate left to right. The equality operators have a lower level of precedence than the relational operators and they also associate left to right. 
	In C, a condition may actually be any expression that generates a zero (false) or nonzero (true) value. То есть если condition есть просто constant отличная от нуля, то условие всегда будет истинным.
		scanf ("%d", &x); 
		printf("%d\n", x>=2);//>= вернет 1 или 0, что и будет напечатано.

		if ( a > b )
			printf("something\n");//The if selection statement expects only one statement in its body—if you have only one statement in the if’s body, you do not need the enclose it in braces.
		if ( a > b ){
			statement1;//To include several statements in the body of an if, you must enclose the set of statements in braces ({ and }). A set of statements contained within a pair of braces is called a compound statement or a block. A compound statement can be placed anywhere in a program that a single statement can be placed. 
			statement2;
		}
		if ( a > b ){
			;//Just as a compound statement can be placed anywhere a single statement can be placed, it’s also possible to have no statement at all, i.e., the empty statement. The empty statement is represented by placing a semicolon (;) where a statement would normally be.
		}
		if ( a > b ){
			//; внутри фигурных скобок не обязателен, хотя в примере про указатели ( s1[ i ] = s2[ i ] ) помещают ; внутрь пустых фигурных скобок. 
		}

	Any expression in C that produces a value can be used in the decision portion of any control statement. 
		if ( payCode == 4 )
			printf( "%s", "You get a bonus!" );
		if ( payCode = 4 )//всегда истинно, пока присваивается ненулеваое значение.
			printf( "%s", "You get a bonus!" );

The if…else Selection Statement, double-selection statement. 
	Simple if…else statements.
		if ( grade >= 60 ) {
		 puts( "Passed" );
		} // end if
		else {
		 puts( "Failed" );
		} // end else
	 
	Nested if…else statements.
		if (/* condition */){
			printf("AAA");
		}
		else if (/* condition */){
			printf("BBB");
		}
		else if (/* condition */){
			printf("CCC");
		}

The conditional operator
	The conditional operator ?: is C’s only ternary operator — it takes three operands. These (three operands) together with the conditional operator ?: form a conditional expression (условное выражение). 
	The first operand grade >= 60 is a condition (условие). 
	The second operand string "Passed" is the value for the entire(всего) conditional expression (условного выражения) if the condition is true.
	The third operand string "Failed" is the value for the entire conditional expression if the condition is false. 
		
		printf( "%s\n" , grade >= 60 ? "2Passed" : "Failed" );
		grade >= 60 ? printf("%s", "Passed") : printf("%s", "Failed" );
		
		day = a > 9 ? 100 : 200 ;
		day == 10 ? a = 1 : a = 0 ;// a = 0 lvalue required as left operand of assignment???
		day == 10 ? (a = 1) : (a = 0) ;//а так работает.    
		a = day == 10 ? 1 : 0 ;

The while Repetition Statement.
	int stud = 0; //stud = 0  - initialized
	while (stud < 3)
	{
		printf("AAA");
		stud = stud + 1;
	}
	AAA
	AAA
	AAA

	int counter = 0;
	while (++counter <= 2) // 0 + 1 ; 1 <= 2 ; print 1
		printf("%d\n", counter);
	printf("%d\n", counter);
	1
	2
	3

	int counter = 0;
	while (counter++ <= 2)  // 0 <= 2 ; 0+1 ; print 1
		printf("%d\n", counter);
	printf("%d\n", counter);    
	1
	2
	3
	4

The for Repetition Statement.
	for ( expression1; expression2; expression3 ){//header. 
			statement;
		}
	In most cases, the for statement can be represented with an equivalent while statement as follows:
		expression1;
		while ( expression2 ){
			statement
			expression3;
		}

		int main( void ){
			int sum = 0;
			int number;
			for ( number = 2; number <= 100; number += 2 ){
				sum += number;
			}
			for (int i = 0; i < 5; ++i){//В стандарте С99 добавили возможность объявления и инициализации переменной внутри цикла for. Тогда i будет экранирована от i в main; см. области действия (scope).
				printf("%d\n", i);
			}
		}

Сomma-Separated Lists (списки) of Expressions. 
	Often, expression1 and expression3 are comma-separated lists of expressions. The commas as used here are actually comma operators that guarantee that lists of expressions evaluate from left to right (гарантирующим выполнение выражений в списке в порядке слева направо, может все же оценивание?). The value and type of a comma-separated list of expressions are the value and type of the rightmost expression in the list (типом и значением списка выражений являются тип и значение самого правого выражения в списке). The comma operator is most often used in the for statement. Its primary use is to enable you to use multiple initialization and/or multiple increment expressions. For example, there may be two control variables in a single for statement that must be initialized and incremented. 
		for ( number = 2; number <= 100; sum += number, number += 2 ){//sum += number; could actually be merged into the rightmost portion of the for header by using the comma operator as follows. The initialization sum = 0 could also be merged into the initialization section of the for. 
			; //empty statement. 
		}

	Постинкремент выглядит естественнее, но прединкремент здесь эквивалентен и выполняется ( или компилируется?) быстрее.
		int main ( void ){
			int i;
			for (i = 0; i <= 2; ++i){
				printf("%d\n", i );
			}
			return 0;
		}

Do While
	int main ( void )
	{
		int counter = 1;
		do 
		{
			printf("%d\n", counter);
		}   while ( ++counter <= 10);
		return 0;
	}

Switch, a multiple-selection statement (с множественным выбором). 
	The switch statement consists of a series of case labels, an optional default case and statements to execute for each case. 
		#include <stdio.h>
		int main ( void )   {
			int grade;
			while ( ( grade = getchar() ) != EOF ) //на первой итерации считывает введенный символ, на следующей итерации считывает enter (10); слева от != будет находиться результат последнего присваивания. Если в терминал с помощью клавиатуры ввести a и нажать enter, то это все является потоком символов код a код enter, то есть 9710, то есть 0110 0001 0000 1010.
			{
				//scanf ("%d", &pas);
				//switch (pas)  
				switch (grade)  //When a switch statement is reached, program execution continues with the statement after the case label with value that matches the value in the parentheses of the switch. If there is no such case label, but there is a default label, program execution continues with the statement after the default label. If there is no default label, program execution continues after the switch. Keyword switch is followed by the variable name grade in parentheses. This is called the controlling expression. The value of this expression is compared with each of the case labels (метками каждого кейса).
				{
					case 'A' : case 'a' : // Еeach individual case can test only a constant integral expression — i.e., any combination of character constants and integer constants that evaluates to a constant integer value. A character constant can be represented as the specific character in single quotes ' '. 
					//A case label consists of: the keyword case, an expression that evaluates to integer constant, a colon.
						printf("this is A or a \n");
						break;
					case 66 : 
						printf("this is B \n");
						break;
					case '\n' : case ' ' : case '\t': // игнор символа переноса, пробела и табов, если работа с символами.
						break;
					default : // все остальные случаи. 
					//A default label consists of: the keyword default, a colon.
						printf("this is other \n");
						break;
				}
			}
			printf("\n End");
			return 0;
		}   
	При отсутсвии brake будет выполнять все следующие операторы до brake или до конца. 
	case '\n' : case 10 - будет ошибка duplicate case value.
	Не путай dec с hex. По-умолчанию, все цифры - это dec!

Break Continue
	The break statement, when executed in a while, for, do…while or switch statement, causes an immediate exit from that statement. 
		int main ( void )   {
			int  x;
			for (x = 1; x <= 10; x++)   {
				if(x == 5)
					break; // break досрочно выводит из цикла, есть и другие структурные способы это сделать.
				printf("%d ", x );
			}
			printf("End %d\n", x);
			return 0;
		}
	The continue statement, when executed in a while, for or do…while statement, skips the remaining statements in the body of that control statement and performs the next iteration of the loop. 
		int main ( void )   {
			int  x;
			for (x = 1; x <= 10; x++)   {
				if(x == 5)
					continue; // continue пропускает оставшийся код, переходит к следующей итерации.
				printf("%d ", x );
			}
			printf("End %d\n", x);
			return 0;
		}

Булева алгебра. 
	В обычной алгебре:
	Операции сложения и умножения коммутативны, их операнды можно поменять местами, а результат не изменится (вычитание и деление некоммутативны):
	A + B = B + A
	A x B = B x A
	Сложение и умножение ассоциативны:
	(A + B) + C = A + (B + C) 
	A х (B x C) = (A x B) x C
	Умножение дистрибутивно относительно сложения:
	A х (B + C) = (A x B) + (A x C)
	Сложение недистрибутивно относительно умножение:
	А + (В х С) = А + (В х С)

	Коммутативный, ассоциативный и дистрибутивный законы действуют и в булевой алгебре. 
	Операции сложения и умножения коммутативны:
	A + B = B + A
	A x B = B x A
	Сложение и умножение ассоциативны:
	(A + B) + C = A + (B + C) 
	A х (B x C) = (A x B) x C
	Умножение дистрибутивно относительно сложения:
	A х (B + C) = (A x B) + (A x C)
	Сложение дистрибутивно относительно умножение:
	А + (В х C) = (А + В) х (A + C)

Logical Operators.
	In expressions using operator &&, make the condition that’s most likely to be false the leftmost condition. In expressions using operator ||, make the condition that’s most likely to be true the leftmost condition. This can reduce a program’s execution time. The equality operators have a lower level of precedence than the relational operators and they also associate left to right.
		int main ( void )   {
			int  a, b, c;
			scanf ("%d%d%d", &a, &b, &c);
			if ( a == 2 )   
				printf("%d==2\n", a);

			if ( !(a == 2) )    
				printf("!(%d==2)\n", a);
			
			if ( b == 1 && c >= 10) 
				printf("%d == 1 && %d >= 10", b, c);
			return 0;
		}

Bitwise Operators 
	The bitwise operators are:
		bitwise AND (&) 
		bitwise inclusive OR (|)
		bitwise exclusive OR (^; also known as bitwise XOR) 
		left shift (<<) 
		right shift (>>) 
		complement (~) (инвертировать, one’s complement)
	Логический сдвиг влево/Logical Shift Left/LSL на 1 разряд увеличивает целое положительное двоичное число вдвое. При логичеком сдвиге вправо/Logical Shift Right/LSR любое четное число уменьшается ровно в 2 раза, а в случае нечетного значения происходит деление нацело, при котором остаток отбрасывается. 
	При сдвиге вправо отрицательных чисел, в отличие от положительных, старший разряд надо заполнять не нулем, а единицей! Чтобы исправить положение, вводится еще одна разновидность сдвига — арифметический сдвиг/Arithmetic Shift Right/ASR. Его единственное отличие от логического состоит в том, что старший (знаковый) бит не меняется, то есть знак числа остается прежним.
	То, что в результате логических сдвигов содержимое крайних разрядов теряется, не всегда удобно. Поэтому в компьютере предусмотрен циклический сдвиг Rotate Right/ROR и Rotate Left/ROL, при котором бит из одного крайнего разряда переносится в другой (“по циклу”).
	Rotate Right with Extend/RRX ?
		#include <stdio.h>
		#include <limits.h>
		void displayBits( unsigned int value );
		int main( void ){
			unsigned int x = 240;
			displayBits( x );
		}
		void displayBits( unsigned int value ){
			printf( "%35u\n", value);
			unsigned int c;
			unsigned int displayMask = 1 << CHAR_BIT * sizeof( unsigned int ) - 1; //The symbolic constant CHAR_BIT (defined in <limits.h>) represents the number of bits in a byte (normally 8).
			//unsigned int displayMask = 1 << 31;// сдвинуть влево 31 раз число 1; это удобно, потому что информация выводится слева направо.
			//displayMask   100000000 00000000 00000000 00000000

			for ( c = 1; c <= CHAR_BIT * sizeof( unsigned int ) ; ++c ) {           
			//for ( c = 1; c <= 32; ++c ) {
				
				putchar( value & displayMask ? '1' : '0' );
				//value             000000000 00000000 00000000 11110000
				//displayMask       100000000 00000000 00000000 00000000
				//v & d             000000000 00000000 00000000 00000000
				//'0'
							
				value <<= 1; // сдвинуть влево на 1 позицию, маска не меняется
				//value             0000 00000 0000 0000 0000 0001 1110 0000

				if ( c % 8 == 0 ) { // вывести пробел после каждого 8 бита
					putchar( ' ' );
				}
			}
			putchar( '\n' );
		}
	Подсчет количества единичных битов.
		int btcnt ( unsigned int value ) {
			unsigned int total = 0;
			while ( value ) {
				if ( value & 1 ) {
					++total;
				}
				value >>= 1;
			}
			return total;
		}

Arrays. 
	Массив средство для резервации нескольких ячеек памяти, а точнее нескольких переменных. Arrays are data structures consisting of related (связанных) data items of the same (одного) type. In Chapter 10, we discuss C’s notion of struct (structure) — a data structure consisting of related data items of possibly different types. Arrays and structures are “static” entities (объекты) (remain the same size throughout program execution). They may be of automatic storage class.
		int MAS[3];//declare MAS as array 3 of int. Будут заняты 3 ячейки, внутри мусор.
		int MAS[3] = {0};//массив с 3 ячейками типа int с нулями; номера ячеек: 0, 1, 2; {0} поместит нули во все ячейки, {1} поместит единицу только в нулевую ячейку, а в остальные - нули.
		int MAS[3] = {1, 2, 3};//Можно перечислять переменные по отдельности. Число перечисленных членов не должно превышать размер массива
		int MAS[ ] = {1, 2, 3};//Можно перечислять переменные по отдельности и размер будет указан автоматически
		char string1 [] = "first";//initializes the elements of array string1 to the individual characters in the string literal "first". The string "first" contains 5 characters plus a special string-termination character called the null character '\0'. 
		char string1 [] = { 'f', 'i', 'r', 's', 't', '\0' };//эквивалентно предыдущему.
		for (int i = 0; string1[i] != '\0' ; ++i)	{
			printf("%c\n", string1[i]);//вывести значение ячейки string1[i]. i subscript - индекс; a subscripted array name is an lvalue — it can be used on the left side of an assignment.
		}
	Программа может выйти за пределы массива, этого нельзя допускать.

Сортировка массивов. Пузырьковая сортировка bubbleSort - меньшие значения всплывают вверх.
	#include <stdio.h>
	#define  SIZE 5
	int main ( void ) {
		int hold;
		int M[SIZE] = {0,4,3,2,1};
		for (int i=0; i < SIZE; i++) {
			printf("%d\n", M[i]);
		}
		for (int n = SIZE - 1 ; n != 0 ; --n ) {//число проходов равно числу промежутков.
			for (int i = 0; i != n ; i++){ //0 удобен утилизацией в качестве индекса; а сравнение происходит каждый раз с "уменьшающимся массивом".
				if (M[ i ] > M[ i+1 ]) {    // хотим, чтобы левый был меньше правого.
					hold    = M[ i ] ;
					M[ i ]  = M[ i+1 ] ;
					M[ i+1 ]= hold ;
				}
			}   
		}
		//for (int pass = 0; pass < SIZE - 1; ++pas ){ // версия у Дейтла.
		//  for (int i = 0; i < SIZE-1  ; i++){ 
		//      if (M[ i ]  > M[ i+1 ]) {
		//          hold    = M[ i ] ;
		//          M[ i ]  = M[ i+1 ] ;
		//          M[ i+1 ]= hold ;
		//      }
		//  }   
		//}
		for (int i=0; i < SIZE; i++) {
			printf("%d\n", M[i]);
		}
		return 0;
	}

Среднее, медиана и наиболее вероятное

Линейный поиск в массивах. Linear Search.
	#include <stdio.h>
	#define SIZE 5
	int findM(int [], int, int);
	int main ( void )	{
		int key;
		int M [SIZE] = {0,1,2,3,4};
		scanf ("%d", &key);
		printf("element=%d\n", findM (M, SIZE, key) );
		return 0;
	}
	int findM (int array[], int size, int key)	{
		for(int i=0; i <= size - 1; i++)
			if (array[i]==key){
				return i;
			}
			return -1;
	}

Двоичный поиск

Multidimensional Arrays. Многомерные массивы.
	int M [rows] [columns or lenght]; // declare M as array rows of array length of int
	Значения группирируются в фигурных скобках по строкам.
		int M [2][2] = {    {1,2} , {3,4} };
				0стлбц  1стлбц
			0стрк//1//  //2//
			1стрк//3//  //4//
		int M [2][2] = {    {1} , {3,4} };
				0стлбц  1стлбц
			0стрк//1//  //0//
			1стрк//3//  //4//
		int M [2][2] = { 1,2,3 };
				0стлбц  1стлбц
			0стрк//1//  //2//
			1стрк//3//  //0//
		int M [][3] = {1,2,3,4};//число строк = 1 + число элементов % длину строки; без указания длины вообще работать не будет, что логично.
				0стлбц  1стлбц  2стлбц
			0стрк//1//  //2//   //3//   
			1стрк//4//  //0//   //0//

	Пример.
		#include <stdio.h>
		#define MAX 100
		#define LEN 80
		char text[MAX][LEN];
		int main(void) {
			register int t, i, j;
			printf("Для выхода введите пустую строку.\n");
			for(t=0; t<MAX; t++) {
				printf("%d: ", t);
				gets(text[t]);
				//gets( &str_array[t][0] );// эквивалетно.
				if(!*text[t]) break;// выход по пустой строке (одно нажатие enter), см. fgets
			}
			for(i=0; i<t; i++) {
				for(j=0; text[i][j]; j++) putchar(text[i][j]);
					putchar('\n');
			}
			return 0;
		}

Pointers. 
	Указатель - это переменная, в которой хранится чей-либо адрес. Выражения с указателями оцениваются по особенным правилам. 
	Просто нужно понимать, что скрывается под именем переменной, что такое указатели, что дают массивы, и тогда элементарно все это понимается с функциями...
	7.2 Pointer Variable Definitions and Initialization
	Pointers are variables whose values are memory addresses. Normally, a variable directly contains a specific value. A pointer, on the other hand, contains an address of a variable that contains a specific value. In this sense, a variable name directly references (непосредственной ссылкой) a value, and a pointer indirectly references (косвенной ссылкой) a value. Referencing a value through (обращение к значению через, ссылка на значение через) a pointer is called indirection (косвенным доступом). 
			 _____
			|count|
				7
		The name count directly references 
		a variable that contains the value 7.
			 _____   ________
			|count|	|countPtr|
				7 <------*
		The pointer countPtr indirectly references 
		a variable that contains the value 7.


	The "Clockwise/Spiral Rule"
	       +-------+
	       | +-+   |
	       | ^ |   |
	  char *str[10];
	   ^   ^   |   |
	   |   +---+   |
	   +-----------+
	str is an...
	str is an array 10 of...
	str is an array 10 of pointers to...
	str is an array 10 of pointers to char

 
		#include <stdio.h>
		int main ( void ) 
		{
			int x = 2;
			printf("%d\n", x);
			printf("%p\n", &x);//%p and %x

			int *Ptr1, *Ptr2; // The definition specifies that variable Ptr1 is of type int * (i.e., a pointer to an integer) and is read (right to left), “Ptr1 is a pointer to int” or “Ptr1 points to an object of type int”. The asterisk (*) notation used to declare pointer variables does not distribute to all variable names in a declaration. 
			char * Ptr3;

			Ptr1 = &x;// Assigns the address of the variable x to pointer variable Ptr1. Variable Ptr1 is then said to “point to” x. The operand of the address operator must be a variable. The address operator cannot be applied to constants or expressions or register. A pointer may be initialized to NULL, 0 or an address. Initializing a pointer to 0 is equivalent to initializing a pointerto NULL, but NULL is preferred. When 0 is assigned, it’s first converted to a pointer of the appropriate type (Когда указателю присваивается значение 0, оно сначала преобразуется в указатель соответствующего типа). (int *) 2 позволяет явно привести тип int к типу указателя на int и без проблем присвоить эту константу указателю.
			printf("%p\n", Ptr1 );
			printf("%d\n", *Ptr1 );
			printf("%p\n", &Ptr1 );


			Ptr1 = (int *) 3000;
			Ptr3 = (char *) 3000;
			Ptr3 = (char *) Ptr1;

			printf("%p\n", * (int *) ch );//175BCD15
			int tttt;
			tttt = *ch;
			printf("%p\n", tttt );//00000015
			y = *( (int *) ch );//Parentheses are not required due to the same precedence.
			printf("%p\n", y);//075BCD15
			//Thus, pointer operations are governed by the type of the pointer, not the type of the object being pointed to.


			printf( "%d\n", x );// 2
			printf( "%p\n", &x );// 0028FF30
			printf( "%p\n", Ptr1 );// 0028FF30
			printf( "%p\n", &Ptr1 );// 0028FF2C; Адрес указателя.
			printf( "%d\n", *Ptr1 );// 2; The unary * operator, commonly referred (часто называемый?) to as the Indirection Operator (оператор косвенного обращения) or Dereferencing Operator (оператор разыменовывания), returns the value of the object to which its operand (i.e., a pointer) points (объекта, на который его операнд (т.е. указатель) указывает). Using * in this manner is called dereferencing a pointer (разыменованием указателя).
			
			Ptr1 = Ptr2;//A pointer can be assigned to another pointer if both have the same type. 
			void * Ptrv;//The exception to this rule is the pointer to void (i.e., void *), which is a generic pointer that can represent any pointer type. All pointer types can be assigned a pointer to void, and a pointer to void can be assigned a pointer of any type. In both cases, a cast operation is not required. A pointer to void cannot be dereferenced. Consider this: The compiler knows that a pointer to int refers to 4 bytes of memory on a machine with 4-byte integers, but a pointer to void simply contains a memory location for an unknown data type—the precise number of bytes to which the pointer refers is not known by the compiler. The compiler must know the data type to determine the number of bytes to be dereferenced for a particular pointer.
			printf("%p\n", sizeof(Ptrv) );// 00000004 ; Зависит от системы. 4 байта - это 4гб озу, тогда адрес любой ячейки (то есть одного байта) - это всегда 4 байта на х86 при х32 ос.
			Ptrv = &x;
			//ER  printf("%d\n", *Ptrv);//;
			printf("%d\n", *( (int *)Ptrv ) );// 666 ; To dereference the pointer, it must first be cast to an integer pointer.
			Ptrv = Ptr3;
			Ptrv = &Ptr3; 
		
			//ER  Ptr1 = &Ptr2;// ; assignment from incompatible pointer type.
			int * * PtrPtr1;// Указатель на указатель ожидает получение адреса int указателя. 
			PtrPtr1 = &Ptr1;
			void * * PtrPtr2;
			PtrPtr2 = &Ptrv;
			//ER  PtrPtr2 = &Ptr1;// странно.
			
			Ptr2 += 2;//would produce 3008 (3000 + 2 * 4), assuming an integer is stored in 4 bytes of memory and address is 3000 ; 3004 (3000 + 2 * 2) if it's stored in 2 bytes. 
			//A pointer may be incremented (++) or decremented (--), an integer may be added to a pointer (+ or +=), an integer may be subtracted from a pointer (- or -=) and one pointer may be subtracted from another.
			x = Ptr2 - Ptr1;//statement would assign to x the number of array elements from Ptr2 to Ptr1, in this case 2 (3008 - 3000).
			
			//Pointers can be compared using equality and relational operators, но есть подробности, смотри раздел ниже.

			printf("%p\n", RtrPtr() );// 0028FF00 ; Вызов функции, которая возвращает указатель; адрес a = 111.
			printf("%d\n", *( RtrPtr() ) );// 111

			printf ("%p\n", &Ptr1);// 0028FF2C ; адрес указателя Ptr1.
			PtrPtrDemonstration (&Ptr1);
			printf ("%p\n", Ptr1);// 00000000 
		}


	In C, there are precedence relationships in declarations. When the default precedence is not what you want, you use explicit parentheses to override it.

		int a ;          //declare a as int
		int a[5] ;       //declare a as array 5 of int
		int a[5][5] ;    //declare a as array 5 of array 5 of int
		int *a ;         //declare a as pointer to int
		int *a[5] ;      //declare a as array 5 of pointer to int
		int   (*a)[5] ;  //declare a as pointer to array 5 of int
		int * (*a)[5] ;  //declare a as pointer to array 5 of pointer to int
		int (*a)[5][5] ; //declare a as pointer to array 5 of array 5 of int

		int a = 3;
		int b = 4;
		int *c[2] = {&a, &b}; // is same as: int *c[] = {&a, &b} ;
		int *c[5]; // same as: int *(a[5]) ;

		int a [2] [3] ; // a is array 2 of array 3 of int
		int b [5] ;// b is array 5 of int
		int (*c) [3] ;// c is pointer to array 3 of int 
		int *d ; // d is pointer to int
		c = & a [0] ; 
		c = a ; 
		d = a [0] ;
		d = & a [0][0] ;
		d = & b [0];
		d = b ;

	Arrays of type T decay into pointers to type T.

	Relationship between Pointers and Arrays. 
	У Дейтлов как-то не очень 
		int *ptr = array; // create pointer to array
	Это неправильно. Wayne Throop has put it, it`s "pointer arithmetic and array indexing [that] are equivalent in C, pointers and arrays are different."

Assember

struct Astra{
		int a;
		int b;
};


int main(void){
	//main:
	// push rbp
	// mov rbp, rsp

	struct Astra data;
	// gcc -m64 doesn't deduct from stack pointer.

	data.a = 1;
  //mov DWORD PTR [rbp-16], 1
	data.b = 2;
  //mov DWORD PTR [rbp-12], 2

	struct Astra *ptr;
	ptr = &data;
  //lea rax, [rbp-16]
  //mov QWORD PTR [rbp-8], rax
	
	(*ptr).a = 3;
  //mov rax, QWORD PTR [rbp-8]
  //mov DWORD PTR [rax], 3
  (*ptr).b = 4;
	//mov rax, QWORD PTR [rbp-8]
 // mov DWORD PTR [rax+4], 4

	return 0;
	mov eax, 0
  pop rbp
  ret
}

Using subscripting and pointer notations with arrays. Pointer to int and pointer to array.
	#include <stdio.h>
	int main ( void )   
	{
		int * Ptr1, * Ptr2;
		int MAS [] = { 10, 20, 30, 40 };// An array name can be thought of as a constant pointer. Которого не существует. Причем важно понимать, что при этом нет ячейки с адресом массива. Имя массива является указателем как бы для компилятора. Называть указателем то, что им не является? А он и не называл, он сказал "можно рассматривать"... Вообще, arrays are not pointers. That's just a behavior of array types and is not meant to imply that they are same thing.

		// ER  int * MAS = { 10, 20, 30, 40 };
		Ptr1 = MAS;// Because the array name (without a subscript) is a pointer to the first element of the array, we can set Ptr1 equal (равным) to the address of the first element in array MAS with the statement; 
		// Но это не значит, что можно легко говорить "указатель на массив". См. Spiral Rule для доказательства. В книгах пишут "int *ptr = array; // create pointer to array". Но int *ptr - это только указатель на int. int (*ptr)[] - это указатель на массив int (причем, конкретно этот имеет неопределенные границы, что будет приводить к ошибкам в некоторых ситуациях).
		Ptr1 = &MAS[0];// Равносильно предыдущему, но нагляднее.
		
		char Array[5] ; 
		char * a = Array ; // Array is pointer to char (or to the first element of Array). The base type of a is char.
		char (*b) [] =  &Array ; // &Array is pointer to whole array of 5 chars. The base type of b is an array of few chars.
		//ER char (*b) [3] = &Array ;//assignment from incompatible pointer type. The base type of b is an array of 3 chars.
		// Array and &Array give same address, but they have different types of addresses. 
		printf("%p %p\n", Array  , &Array   ) ;// 0028ff33 0028ff33
		printf("%p %p\n", Array+1, &Array+1 ) ;// 0028ff34 0028ff38
			
		char (*b2) [5] =  &Array ;//otherwise will invalid use of array with unspecified bounds.
		printf("   %p\n",          b2   ) ;// 0028ff33
		printf("   %p\n",          b2+1 ) ;// 0028ff38

		//Pointers can be compared using equality and relational operators, but such comparisons are meaningless unless the pointers point to elements of the same array. Pointer comparisons compare the addresses stored in the pointers. A comparison of two pointers pointing to elements in the same array could show, for example, that one pointer points to a higher-numbered element of the array than the other pointer does. A common use of pointer comparison is determining whether a pointer is NULL.

		puts ("int MAS[] = { 10, 20, 30, 40 };" );
		puts ("int * Ptr1 = MAS;" );
		puts ("i  Ptr1+i     &MAS[i]   *(Ptr1+i)  Ptr1[i]  MAS[i]  *(MAS+i)  *(&MAS[0]+i)");
		for (int i = 0; i != 4; ++i)
		{
			printf("%d %p %p  %d        %d      %d      %d        %d\n", 
				i, Ptr1+i, &MAS[i], *(Ptr1+i), Ptr1[i], MAS[i], *(MAS+i), *(&MAS[0]+i) );   
		}
		//ER  printf ("%d\n", *Ptr1[2] );// Ptr1[2] это фича, элемент массива, а не указатель, который можно разыменовать; is not a pointer and should not be dereferenced.
	}

	int MAS[] = { 10, 20, 30, 40 };
	int * Ptr1 = MAS;
	i Ptr1+i    &MAS[i]     *(Ptr1+i) Ptr1[i] MAS[i]  *(MAS+i)    *(&MAS[0]+i)
	0 0028FF18  0028FF18    10        10      10      10          10
	1 0028FF1C  0028FF1C    20        20      20      20          20
	2 0028FF20  0028FF20    30        30      30      30          30
	3 0028FF24  0028FF24    40        40      40      40          40
	// Pointer/offset notation *(Ptr1+offset) where the pointer is the array name. The parentheses are necessary because the precedence of * is higher than the precedence of +. 
	// Pointer subscript notation Ptr1[i]. Pointers can be subscripted like arrays. If Ptr1 has the value MAS, the expression refers to the array element MAS[1]. &Ptr1[i] равен &MAS[i].
	// Array subscript notation MAS[i]. An array name can be thought of as a constant pointer. 
	// Pointer/offset notation *(MAS+offset). The array itself can be treated as a pointer and used in pointer arithmetic.

	#include <stdio.h>
	int main(void)
	{
		int M[5] = { 2 };
		int(*ptr)[5] = M;
		printf("%d\n", (*ptr)[0]);
		int* arr = *ptr;
		printf("%d\n", arr[0]);
		return 0;
	}

Pointers and multidimensional arrays.
	int A [10][10];
	These two statements are equivalent:
		a
		& A [0][0]
	In general, for any two-dimensional array int A [rows][lenght] :
		A [row][column] 
		*( (base type *) A + (length*row) + column )//The cast of the pointer to the array into a pointer of its base type is necessary in order for the pointer arithmetic to operate properly. 
	These two statements are equivalent:
		A [1][2] 
		*( (int *) A + (1*10) + 2 )

		#include "stdio.h" 
		int main() 
		{ 
			char Array[10][5] ; 
			char (* b) [ ] = Array ;// Array is pointer to array of 5 char. The base type of b is an array of few chars.
			//ER char (*b) [4] = &Array ;//assignment from incompatible pointer type. 
			char (*d) [ ][5] = &Array ; // &Array is pointer to array of 10 rows arrays of 5 char. The base type of d is an array of few rows arrays of 5 char.
			printf("%p %p\n", Array  , &Array   ) ;//0028fefe 0028fefe
			printf("%p %p\n", Array+1, &Array+1 ) ;//0028ff03 0028ff30

			char (*b2) [5] =  Array ;//otherwise will invalid use of array with unspecified bounds.
			char (*d2) [10][5] = &Array ;
			printf("%p %p\n", b2,   d2   ) ;//0028fefe 0028fefe
			printf("%p %p\n", b2+1, d2+1 ) ;//0028ff03 0028ff30
			return 0; 
		}

Const Qualifier. Работает с компилятором.
	//У указателей как-то задом наперед... 
	//Как раз все правильно, если правильно писать.
	int main (void) {
		int a = 5;
		int const b = 9;//b is nearly read-only integer
		const int c = 11;//old shit

		int* ptr1;
		int const* ptr2;//ptr2 is pointer to nearly read-only int
		const int * ptr22;//old shit 
		ptr2 = &b;
		ptr2 = &c;

		int* const ptr3 = &a;//ptr3 is nearly read-only pointer to int
		return 0;
	}

	void func( int x, const int y, int MAS1 [], const int MAS2 [], int * aPtr, const int * bPtr; int * const cPtr; const int * const dPtr ) 
	{//Если передавать const сущность в non-const параметр функции, который может изменить значение const сущности, то будет ошибка, даже если нет ни одной изменяющей инструкции. 
	//А вот если по-отдельности скомпилировать, то прекрасно линкуется кост переменная с функцией нон-конст указателем...
		Эта же муть на 10 страниц, опережая все и вся. Six possibilities exist for using (or not using) const with function parameters: 2 with pass-by-value parameter passing and 4 with pass-by-reference parameter passing.
	}

Work with functions and Bubble Sort Using Pass-by-Reference.
	#include <stdio.h>
	#define SIZE 10
	void func1( int * Ptr );
	void func2( int BAS [] );
	void printMAS( int * Ptr );
	void bubbleSort( int * const array, const int size );
	int main ( void )   {
		int MAS [SIZE] = {2,6,4,8,10,12,89,68,45,37};
		printf ("%p\n", MAS);//0028FF24
	
		func1 (MAS);
		func2 (MAS);
	
		printMAS (MAS);
		bubbleSort (MAS, SIZE);
		printMAS (MAS);
		return 0;   
	}
	void func1( int * Ptr ) {// If the pointer is a function parameter, it’s initialized with a pointer that’s passed to the function; это известно еще с функций.
		printf ("%p\n", &Ptr[0] );//0028FF24
		printf ("%d\n", Ptr[0] );//2
		printf ("%p\n", Ptr );//0028FF24
		printf ("%d\n", *Ptr );//2
		return; 
	} 
	void func2( int BAS [] ) {//When the compiler encounters a function parameter for a single-subscripted array of the form int BAS[], the compiler converts the parameter to the pointer notation int *BAS. The two forms are interchangeable.
		printf ("%p\n", &BAS[0] );//0028FF24
		printf ("%d\n", BAS[0] );//2
		printf ("%p\n", BAS );//0028FF24
		printf ("%d\n", *BAS );//2
		return; 
	}
	void printMAS( int * Ptr)   {
		for (int i = 0; i < SIZE; ++i) {
			printf("%4d\n", Ptr[i]);
		}
		puts ("");
		return; 
	}
	void bubbleSort(int * const array, const int size) {
		void swap(int * , int * );
		for (int pass = size - 1; pass != 0; --pass) {  
			for (int i = 0; i != pass; i++) {
				if (array[i] > array [ i + 1])              {
					swap( &array[i] , &array[i+1] );//можно было бы заменить на (array+i) и (array+i+1), но так удобнее.
				}
			}
		}
		//for ( int pass = 1; pass < size ; ++pass ) {  // версия у Дейтла.
		//  for ( int count = 0; count < size -1; ++j ) {
		return; 
	}
	void swap (int * element1Ptr, int * element2Ptr) {
		int hold;
		hold = *element1Ptr;
		*element1Ptr = *element2Ptr;
		*element2Ptr = hold;
		return; 
	}

String Copying with Arrays and Pointers. 
	Из-за этого примера пришлось все переосмыслить. 
		#include <stdio.h>
		#define SIZE 10
		void copy1( char * const s1, const char * const s2 );
		void copy2( char *s1, const char *s2 );
		int main ( void )   
		{
			printf("%s\n", "Memory   Value    Symbol" );
			// Memory   Value    Symbol

			char string1 [SIZE], string2 [SIZE];
			char string3 [] = "Good Bye";
			char * string4 = "Hello";// Объявление non-const указателя (сам указатель занимает ячейку в памяти) и инициализация его адресом строки (обозначенной строковым литералом). Так делать не желательно, см ниже.
			const char * string5 = "Hello";// When a variable of type char * is initialized with a string literal, some compilers may place the string in a location in memory where it cannot be modified. If you might need to modify a string literal, it should be stored in a character array to ensure modifiability on all systems. 
			// Зачем указателям такие возможности со строками? Можно обойтись без этого: инициализировать множество символьных массивов разных длин (или двумерный массив), объявить массив указателей, каждый указатель инициализировать своим массивом. Но это неудобно, а строки являются человеческими словами очень разной длины и часто используются  для описания, например, меню или пунктов.
			// ER  scanf ("%s", string5 );
			// Всевозможные варианты не работают (даже если нет const). Как изменить строку, инициализированную при объявлении массива символьных указателей, с помощью scanf? qna.habr.com/q/521784 , qna.habr.com/q/674794 . В данном случае только выделить память для новой строки, сделать scanf туда, присвоить указатель на выделенную память элементу массива suit. Напрямую в первоначальный массив никак, потому что указатели указывают на константные строки (а возможность писать char * вместо const char * это устаревшее средство обеспечения совместимости с древними версиями стандарта). 
			// Поэтому если параметр функции не является const, то происходит предупреждение, ведь тогда функция разрешает изменение содержимого элементов массива suit.
			
			// Сначала указатель, потому что он, как ни странно, понятнее.
			printf("%p %p \n", &string4, string4 );
			printf("%p %p \n", (string4+0), *(string4+0) );// равнозначно &string4[0], string4[0]
			// 0028FEEC 0040B07D
			// 0040B07D 00000048

			for (int i = 0;  *(string4+i) != '\0'; ++i) 
			{
				printf("%p %p %c\n", (string4+i), *(string4+i), string4[i] );// 2 нотации для примера.
			}
			puts("");
			// 0040B07D 00000048 H
			// 0040B07E 00000065 e
			// 0040B07F 0000006C l
			// 0040B080 0000006C l
			// 0040B081 0000006F o

			// Затем массив. &string3 нежелательно и только для примера, так может только printf; нужно string3 или &string3[0] .
			printf("%p %p \n", &string3, string3 );  
			printf("%p %p \n", (string3+0), *(string3+0) );// равнозначно &string3[0], string3[0] 
			// 0028FEF3 0028FEF3
			// 0028FEF3 00000047

			for (int i = 0;  *(string3+i) != '\0'; ++i) 
			{
				printf("%p %p %c\n", (string3+i), *(string3+i), string3[i] );// 2 нотации для примера.
			}
			puts("");
			// 0028FEF3 00000047 G
			// 0028FEF4 0000006F o
			// 0028FEF5 0000006F o
			// 0028FEF6 00000064 d
			// 0028FEF7 00000020
			// 0028FEF8 00000042 B
			// 0028FEF9 00000079 y
			// 0028FEFA 00000065 e

			copy1( string1, string3 );
			printf( "%s\n", string1 );
			// Good Bye
			copy2( string2, string4 );
			printf( "%s\n", string2 );
			// Hello
		}
		void copy1( char * const s1, const char * const s2 ) 
		{//cosnt на всякий случай.
			for (size_t i = 0; ( s1[ i ] = s2[ i ] ) != '\0' ; ++i ) 
			{//слева от != будет находиться результат последнего присваивания.
				;//после последнего s1[ i ] равного \0 произойдет ложность условия и ++i не будет выполнено, произойдет выход из for.
			}
		}
		void copy2( char * s1, const char * s2 ) 
		{//cosnt на всякий случай.
			for ( ;  ( *s1 = *s2 ) != '\0' ; ++s1, ++s2 ) 
			{ 
				;
			}
		}
	
Arrays of Pointers. 
	Arrays may contain pointers. A common use of an array of pointers is to form an array of strings, referred to simply as a string array. 
		#include <stdio.h>
		void deal( const char * duit [] );
		//void deal( const char * * duit );
		int main() {
			// int * MAS [4];//Массив из 4 указателей типа int с garbage или ={0} или ={NULL}.
			// ER  int * MAS [4] = { 10, 20, 30, 40 };
			// int * MAS [4] = { (int *)10, (int *)20 };
			char const * suit [4] = { "Hearts", "Diamonds" };// The suit[4] portion of the definition indicates an array of 4 elements. The char * portion of the declaration indicates that each element of array suit is of type “pointer to char.” Qualifier const indicates that the strings pointed to by each element pointer will not be modified (IN THIS SOURCE FILE. And it need for corresponding: "hearts" is stored in non-change memory, so pointer must not be amending. 
			//The four values to be placed in the array are "Hearts", "Diamonds", "Clubs" and "Spades".
			suit [2] = "Hello";
			printf ("%c\n", suit [2][1] );//e
			// e
			
			for (int i = 0; i != 2; ++i) 
			{
				printf("%p ", (suit+i)      );// равнозначно &suit[i] 
				printf("%p ", *(suit+i)     );// равнозначно suit[i], 
				printf("%p\n", *(*(suit+i)) );// равнозначно *(*(suit+i))
			}
			puts("");   
			// 0028FF1C 0040B064 00000048
			// 0028FF20 0040B06B 00000044
			
			for (int i = 0; i != 2; ++i) 
			{
				for (int j = 0;  *(suit[i] + j) != '\0' ; ++j) 
				{
					printf("%p ", suit [i] + j      );
					printf("%p ", * ( suit[i] + j ) );
					printf("%c\n", suit [i] [j]     );
				}
				puts("");   
			}
			// 0040B064 00000048 H
			// 0040B065 00000065 e
			// 0040B066 00000061 a
			// 0040B067 00000072 r
			// 0040B068 00000074 t
			// 0040B069 00000073 s
			
			// 0040B06B 00000044 D
			// 0040B06C 00000069 i
			// 0040B06D 00000061 a
			// 0040B06E 0000006D m
			// 0040B06F 0000006F o
			// 0040B070 0000006E n
			// 0040B071 00000064 d
			// 0040B072 00000073 s

			deal( suit );
		}
		void deal( const char * duit[] ) {//duit is array of pointers to char
		//void deal( const char * * duit ) {//duit is a pointer to contstant pointer to char
			for (int i = 0; i != 2; ++i) 
			{
				printf ("%s ", duit[i] );
			}
			// Hearts Diamonds
		}   

Functions. 
	#include <stdio.h>//printf()

	//Function declaration
	int func ( int x );//function prototype, технически его может не писать, если код функции описан до вызова функции, тогда компилятор создаст его сам.
	void print ( void );//function prototype.
	//int square( int y ); is a function prototype. The int in parentheses informs the compiler that square expects to receive an integer value from the caller. The int to the left of the function name square informs the compiler that square returns an integer result to the caller. The compiler refers to the function prototype to check that any calls to square (line 14) contain the correct return type, the correct number of arguments and the correct argument types, and that the arguments are in the correct order.
	//Another important feature of function prototypes is the coercion of arguments (The word coercion is used to denote an implicit conversion), i.e., the forcing of arguments to the appropriate type. For example, the math library function sqrt can be called with an integer argument even though the function prototype in <math.h> specifies a double parameter, and the function will still work correctly. The statement printf("%.3f\n",sqrt(4)); correctly evaluates sqrt(4) and prints the value 2.000. The function prototype causes the compiler to convert a copy of the integer value 4 to the double value 4.0 before the copy is passed to sqrt. In general, argument values that do not correspond precisely to the parameter types in the function prototype are converted to the proper type before the function is called. These conversions can lead to incorrect results if C’s usual arithmetic conversion rules are not followed. 
	//If there’s no function prototype for a function, the compiler forms its own function prototype using the first occurrence of the function—either the function definition or a call to the function. This typically leads to warnings or errors, depending on the compiler. 
	//A function prototype placed outside any function definition applies to all calls to the function appearing after (следующим после) the function prototype in the file. A function prototype placed in a function applies only to calls made in that function. 

	int main ( void ) {
		int x;//declaration with definition (see linkage, see extern)
		x = 2;//initialization
		printf ("%d", func (2) );//function call with 2 - basically like initializations
		print ();//если void , то в скобках должно быть пусто.
		return 0;
	}

	//Function definition
	//return_value_type function_name (parameter_list aka formal_parameters)header - basically like definitions, correctly "header of function", non "header files", also signature.
	int func ( int x ) //The original version of C included a feature that is sometimes described as the "implicit int" rule (also called the "default to int" rule). This rule states that in the absence of an explicit (в отсутствие явного) type specifier, the type int is assumed. This rule was included in the C89 standard, but has been eliminated by C99. (It is also not supported by C++.)
	{ //Body (or block)
		//definitions;
		//statements;
		//The definitions and statements within braces form the function body, which is also referred to as a block (которое также называется блоком). Variables can be declared in any block, and blocks can be nested.
		//All variables defined in function definitions are local variables — they can be accessed only in the function in which they’re defined.
		//Each time a function calls another function, an entry is pushed onto the stack. This entry, called a stack frame, contains the return address that the called function needs in order to return to the calling function. Most functions have automatic variables. When a called function returns to its caller, the called function’s automatic variables need to “go away.” When that function returns—and no longer needs its local automatic variables — its stack frame is popped from the stack, and those local automatic variables are no longer known to the program.
		
		return x * x;//There are three ways to return control from a called function to the point at which a function was invoked: 
	}
		//If the function does return a result, the statement return expression; returns the value of expression to the caller; 
		//A return with a value can be used only in a function with a non-void return type. In this case, the value associated with return becomes the return value of the function. 
			//	non-void foo ( parameters ){
			//		return value;
			//	}
		//Technically, in C89, a return statement in a non-void function does not have to return a value. If no return value is specified (если не указано возвращаемое значение в return инструкции), a garbage value is returned. However, in C99, a return statement in a nonvoid function must return a value. This is also true for C++.
			//	non-void foo ( parameters ){
			//		return; //garbage in 89, error in C99, error in CPP.
			//	}
		//main’s Return Type. Notice that main has an int return type. The return value of main is used to indicate whether the program executed correctly. In earlier versions of C, we’d explicitly place return 0; at the end of main—0 indicates that a program ran successfully. The C standard indicates that main implicitly returns (неявно возвращает) 0 if you to omit the preceding statement (если вы пропустите предшествующую инструкцию)—as we’ve done throughout this book. You can explicitly return non-zero values from main to indicate that a problem occured during your program’s execution. For information on how to report a program failure, see the documentation for your particular operating-system environment. 
			//	int main ( parameters ){
			//		;
			//	}
		//If the function does not return a result, control is returned simply when the function-ending right brace is reached or by executing the statement return. 
			//	void foo ( parameters ){
			//		;
			//	}
			//	void foo ( parameters ){
			//		return;
			//	}

	// A function can be without parameters, in which case the parameter list is empty.
	void print( ) { 
		printf("HELLO\n");
		return;
	}
	// An empty parameter list can be explicitly specified as such by placing the keyword void inside the parentheses.
	void print( void ) {
		printf("HELLO\n");
		return;
	}

	//Early versions of C did not define the void keyword. Thus, in early C programs, functions that did not return values simply defaulted to type int, even though no value was returned.
	//K&R 
	// double atof();
	//Проверка соответствия параметров для atof просто отключается. Это особое значение пустого списка аргументов введено для того, чтобы старые программы на С могли компилироваться новыми компиляторами. Однако использовать этот стиль в новых программах — дурной тон. Если функция принимает аргументы, объявляйте их. Если же она не принимает никаких аргументов, пишите void.

	//In C: 	
	void foo() {} // a function foo taking an unspecified number of arguments of unspecified type 
	void foo(void) {} // a function foo taking no arguments
	
	//In C++:
	void foo() {} // a function foo taking no arguments
	void foo(void) {} // a function foo taking no arguments
	
	// Нужно понимать передачи и возврата значений. Маленькие возвраты - регистры, большие возвраты - стек вызывающего, маленькие передачи и большие передачи - стек вызывающего. Если main вызывает f, то компилятору нужен только прототип f. Компилятор будет использовать регистр с надеждой, что функция поместит осмысленное значение в этот регистр. 

	int AAA ( int aaa );
	int main ( void ) {
		printf("%d", AAA(2) );
		return 0;
	}
	int AAA(int aaa) {
		int BBB ( int bbb );//можно скрыть прототип от остальных
		return BBB(aaa);
	}
	int BBB(int bbb) {//без прототипов функция должна идти роньше вызывающей функции.

		return bbb * 1000;
	}

Рекурсия. 
	Всё, что можно написать рекурсией - можно написать и итерацией. Нужно выбирать подход в зависимости от обстоятельств. Рекурсия требует больше ресурсов. 

	Факториал рекурсивный.
		#include "stdio.h"
		int foo(int);
		int main ( void ){
			int number = 5;
			printf ( "%d", foo(number) );
			return 0;
		}
		int foo( int x ){
			printf ( "%d\n", x );//получен х
			if( x <= 1 ){//базовый случай.
				return 1;
			}
			else{
				return( x * foo( x - 1 ) );//вычесть 1 из х и передать его в функцию
			}   

		}

	Или так:
		#include "stdio.h"
		int fact(int x);
		int main ( void ){
			printf ("%d\n", fact (5) );
		}
		int fact(int x){
			return x == 1 ? 1: x * fact( x - 1 );
		}

	Задание 4.14. Факториал итеративный.
		int main ( void )
		{
			int x,i;
			scanf ("%d", &x);
			i = 1;
			while (x > 1)
			{
				i *= x;
				--x;
			}
			printf("%d\n", i );
			return 0;
		}

		mov 5, r0
		call fact
		stop

		fact:
		push r1; бекап регистра r1
		mov 1, r1 ; понеслась
		a:
		mul r0, r1 ; 5 * 1 = 5 , поместить в r1
		sub 1, r0 ;  5 - 1 = 4 , поместить в r0
		jnz a
		mov r1, r0
		pop r1 ; применение бэкапа
		ret



		void reverse( const char * const sPtr ) 
		{
			int x;
			if ( '\0' == sPtr[ 0 ] ) {
				return;
			}
			else { 
				reverse( &sPtr[ 1 ] );
				putchar( sPtr[ 0 ] );
			} 
			return;
			//1 reverse( &sPtr[ 1 ] );
			//2											reverse( &sPtr[ 1 ] );
			//3																					reverse( &sPtr[ 1 ] );
			//4																															return;
			//3																					putchar( sPtr[ 1 ] );
			//2											putchar( sPtr[ 1 ] );
			//1 putchar( sPtr[ 1 ] );
		} 

C Preprocessor.
	Каждая стандартная библиотека имеет соответствующий заголовочный файл, содержащий прототипы всех функций в этой библиотеке, а также определения различных типов данных и констант, необходимых этим функциям. Можно создавать собственные заголовочные файлы. Подробнее в главе 13. Директивы сообщают препроцессору о необходимости включения заголовочных файлов. Заголовочные файлы .h в английском просто header, легко спутать с header-ом функции.
	Preprocessor directives:
		#include "square.h" - файл лежит в рабочей директории.
		#include <stdio.h> printf(), scanf (), NULL, sizeof(), getchar()
		#include <stddef.h> NULL, size_t
		#include <stdlib.h> system(), rand()
		#include <math.h> 
		#include <time.h> time(NULL)
		#include <unistd.h> sleep()
		#include <stdint.h> intN_t где N:8,16,32, uintN_t где N:8,16,32.

	The #define directive format is
		#define identifier replacement-text
	When this line appears in a file, all subsequent occurrences of identifier (that do not appear in string literals) will be replaced by replacement text automatically before the program is compiled. The #define directive creates symbolic constants (constants represented as symbols) and macros (operations defined as symbols). A symbolic constant is a type of macro.
	Symbolic constants.
		#define PI 3.14//symbolic constant PI whose value is 3.14 . Replaces all subsequent occurrences (последующие вхождения) of the symbolic constant PI with the numeric constant 3.14.
		#define F 80+20
			int a = F * 2;//the expression is expanded to 
			int a = 80+20 * 2;
		#define F (80+20)
			int a = F * 2;//the expression is expanded to 
			int a = (80+20) * 2;
	Macros.
	Macros may be defined with or without arguments. A macro without arguments is processed like a symbolic constant. In a macro with arguments, the arguments are substituted in the replacement text, then the macro is expanded—i.e., the replacement-text replaces the identifier and argument list in the program. A symbolic constant is a type of macro.
	Consider the following macro definition with one argument for the area of a circle:
		#define CIRCLE_AREA(x) ((PI) * (x) * (x))//Macros with one argument x. 
		//Wherever CIRCLE_AREA(y) appears in the file, the value of y is substituted for x (почему не the x is substituted for the value of y?) in the replacement-text, the symbolic constant PI is replaced by its value (defined previously) and the macro is expanded in the program.  
		//For example, the statement:
			area = CIRCLE_AREA( 4 );//is expanded to    
			area = ( (3.14159) * (4) * (4) );//then, at compile time, the value of the expression is evaluated and assigned to variable area.
		#define RECTANGLE_AREA(x, y) ((x) * (y))
			rectArea = RECTANGLE_AREA(a + 4, b + 7);//the statement is expanded to 
			rectArea = ((a + 4) * (b + 7));//The value of the expression is evaluated at runtime and assigned to variable rectArea. 
		#define MASK(x) ( (x) & 0xFF)
			int a = MASK(4095);//the expression is expanded to 
			int a = ( (4095) & 0xFF);   
				
		#define getchar() getc(stdin)//gethcar будто функция с void
		
		#if 0
		// The expression that follows the #if is evaluated at compile time. Therefore, it must contain only previously defined identifiers and constants— no variables may be used
			code prevented from compiling;
		#endif

		#if DEBUG == 0 //Нет ошибки, если DEBUG не объявлен; есть ошибка, если DEBUG объявлен без numeric constant.
			printf("DEBUG == 0");
		#else   //Notice that #else is used to mark both the end of the #if block and the beginning of the #else block. This is necessary because there can only be one #endif associated with any #if.
			printf( "ELSE" );
		#endif

		#define US 0
		#define ENGLAND 1
		#define FRANCE 2
		#define ACTIVE_COUNTRY US
		#if ACTIVE_COUNTRY == US
			char currency[] = "US";
		#elif ACTIVE_COUNTRY == ENGLAND// #elif is followed by a constant expression. If the expression is true, that block of code is compiled and no other #elif expressions are tested. Otherwise, the next block in the series is checked. 
			char currency[] = "ENGLAND";
		#elif ACTIVE_COUNTRY == FRANCE
			char currency[] = "FRANCE";
		#else
			char currency[] = "XYZ";
		#endif
		
		#if defined (DEBUG) 
			printf( "DEBUG" );
		#endif
		#if !defined (DEBUG) 
			#define START 1
			printf( "NOT DEBUG" );
		#endif
		
		#ifdef DEBUG //без скобок
			printf( "DEBUG" );
		#endif
		#ifndef DEBUG
			#define START 1
			printf( "NOT DEBUG" );
		#endif

		//grandfather.c
		#ifndef CHTO_YGODNO, NO LYCHSHE H_GRANDFATHER
			#define H_GRANDFATHER
			int a = 1 ;
		#endif
		//father.c
		#include "grandfather.c"
		//child.c
		#include "grandfather.c"
		#include "father.c"

		#define LEN 100
		#define WIDTH 100
		char array[LEN][WIDTH];
		#undef LEN
		#undef WIDTH
		/* at this point both LEN and WIDTH are undefined */

		#define HELLO(x) puts("Hello, " #x ) ;//stringize
			HELLO(John) ;
			puts("Hello, " "John" ) ;
		
		#define CONCAT(a, b) a ## b//pasting
			printf("%d", CONCAT(x, y));
			printf("%d", xy);
		
	1.c// Исходник совместно с директивами для препроцессора.
	gcc -E 1.c -o 1E.c // Preprocess only; do not compile, assemble or link. 
	//Препроцессор включает в основной файл содержимое всех заголовочных файлов. В результате получается файл исходного кода с включённым в него содержимым заголовочных файлов. Например, в него войдет весь код заголовочного файла stdio.h. Кроме того, препроцессор сюда добавляет некоторые теги, указывающие компилятору способ связи с объявленными функциями. Основной текст нашей программы виден только в самом низу.
	gcc -S 1.c -o 1.s//Compile only; do not assemble or link. 
	//Компиляция исходника в асм, .s файл. 
	//Нет разницы между компиляцией 1.c и 1E.c кроме .file "name" .
	gcc -c 1.c -o 1.o//Compile and assemble, but do not link. 
	//Объектный файл .o из исходника, который представляет собой перевод программного кода на машинный язык, пока без связи вызываемых функций с их определениями. Объектный файл нельзя запустить на выполнение, потому что в нем нет информации о том, каким образом файл должен загружаться в память при выполнении и нет информации о расположении внешних процедур, на которые может ссылаться приложение. 
	//Нет разницы между ассемблированием 1.c и 1E.c (1E.s) кроме g.name.c . Логично, ведь асм код одинаковый.
	??? gcc -x none -c 1E.c -o 1.o 
	//Если мы создаём объектный файл из файла, уже обработанного препроцессором, то нужно уведомить об этом. В противном случае он будет обрабатываться, как обычный файл C++ ???, без учёта директив препроцессора, а значит связь с объявленными функциями не будет устанавливаться. -x <language> Specify the language of the following input files. Permissible languages include: c c++ assembler none. "none" means revert to the default behavior of guessing the language based on the file’s extension.
	gcc 1.o 2.o ... -o 1.exe
	// Cкомпоновать файлы 1.o и 2.o в единый исполняемый файл 1.exe. Компоновщик связывает: объектные файлы в один, вызовы функций с их определениями, присоединяет библиотечные файлы с функциями, которые вызываются, но не определены в проекте. Определяется расположение различных сегментов программного кода и данных в адресном пространстве, а также разрешаются ссылки на внешние по отношению к данному модулю процедуры.

Storage Classes. Linkage. 

	C defines three categories of linkage: external, internal, and none. 
	In general, functions and global variables have external linkage. This means they are available to all files that constitute a program. 
	File scope objects declared as static (described in the next section) have internal linkage. These are known only within the file in which they are declared. 
	Local variables have no linkage and are therefore known only within their own block.

	We used identifiers for variable names. The attributes of variables include: 
	1. Name. 
	2. Type. 
	3. Size (data type sizes). 
	4. Value. 

	Variables can be declared in three places:
		Inside functions (local variables, aka automatic variables). Variables that are declared inside a function are called local variables. In some C literature, these variables are referred to as automatic variables. This book uses the more common term local variable. Unless otherwise specified, local variables are stored on the stack. The fact that the stack is a dynamic and changing region of memory explains why local variables cannot, in general, hold their values between function calls; 
		In the definition of function parameters (formal parameters). Even though the formal parameters receive the value of the arguments passed to the function, they otherwise act like normal local variables. For example, you can make assignments to a parameter or use one in any allowable expression. Keep in mind that, as local variables, they are also dynamic and are destroyed upon exit from the function;
		And outside of all functions (global variables). Storage for global variables is in a fixed region of memory set aside for this purpose by the compiler. Global variables are helpful when many functions in your program use the same data. You should avoid using unnecessary global variables, however. They take up memory the entire time your program is executing, not just when they are needed.   

	We also use identifiers as names for user-defined functions. Actually, each identifier in a program has other attributes, including storage class, storage duration, scope and linkage.

	5. Storage class. C provides the storage class specifiers: 
		auto, 
		static, 
		extern,
		register (archaic), 
		_Thread_local.
	An identifier’s storage class determines: storage duration, scope, linkage.

	6. Storage duration. 
		Automatic storage duration:
			auto - variables with automatic storage duration are created when the block in which they’re defined is entered; they exist while the block is active, and they’re  destroyed when the block is exited;
			register - .
		Static storage duration: 
			static - for static variables, storage is allocated and initialized only once, before the program begins execution. For functions, the name of the function exists when the program begins execution;
			extern - global variables and function names are of storage class extern by default. Global variables are created by placing variable declarations outside any function definition, and they retain their values throughout the execution of the program.   
				
		The principal use of extern is to specify that an object is declared with external linkage elsewhere in the program. To understand why this is important, it is necessary to understand the difference between a declaration and a definition. A declaration declares the name and type of an object. A definition causes storage to be allocated for the object. The same object may have many declarations, but there can be only one definition. In most cases, variable declarations are also definitions. However, by preceding a variable name with the extern specifier, you can declare a variable without defining it. Thus, when you need to refer to a variable that is defined in another part of your program, you can declare that variable using extern.

	7. Scope. 
		The four identifier scopes:
			block {} - local variables defined at the beginning of a function, function parameters, which are considered local variables by the function;  
			file - an identifier declared outside any function, gloobal variables, function definitions, and function prototypes; 
			function-prototype - (int funk(int), прототипы требуют только типы идентификаторов, имена им не нужны, но имя можно указать (int funk(int var), тогда оно будет выводится при ошибках компиляции. И имя может быть вообще любым int funk(int lol), ведь его область действия ограничена только прототипом. 
			function - labels (identifiers followed by a colon such as start:) are the only identifiers with function scope. Labels can be used anywhere in the function in which they appear, but cannot be referenced (не доступны) outside the function body. Labels are used in switch statements (as case labels) and in goto statements (see Chapter 14);

		There are 4 namespaces in C, see 6.2.3 in the C99 Standard:
			label names
			the tags of structures, unions, and enumerations
			the members of structures or unions (not a single name space ... as many as structures or unions are defined)
			global name space, for all other identifiers

			int main(void) {
			  struct test {//struct tag name space... just about
			    int x;
			    int y;
			  };
			  int test = 5;//global name space
			  struct test var;//var in global name space
			  //test var; // works in C++ if there's no ambiguous (int test, for example)
			  return 0;
			}

			// ок в Си, не ок в С++
			int main() {
			  struct foo
			  {
			      int a;
			  };
  
			  typedef struct bar
			  {
			      int a;
			  } foo;
			}

	Fig. 5.16: fig05_16.c //Scoping.
		//gcc -c main.c
		//gcc -c file1.c
		//gcc -c file2.c
		//gcc main.o file1.o file2.o

		//main.c//
		#include <stdio.h>
		#include "file1.h"
		#include "file3.h"
		#include "max.h"

		void useLocal( void ); // function prototype
		void useStaticLocal( void ); // function prototype
		void useGlobal( void ); // function prototype

		int x = 1;// global variable. Global variables and functions that are not preceded by static in their definitions have external linkage—they can be accessed in other files if those files contain proper declarations and/or function prototypes. 
		//Warning если дописать extern, потому что глобальные переменные с non-static и non-const и так имеют extern linkage (и вдобавок компилятор будет думать, что это forward declaration). Extern применяется к переменным, которые ссылаются на ужЕ существующую глобальную переменную, чтобы объявить переменную, но не определять ее (потому что определена она где-то в другом месте), или для глобальных переменных с const (??? статик) (потому что у таких переменных как раз по-умолчанию идет internal linkage XD )...
		int a = 666;
		static int b = 2;// The storage-class specifier static, when applied to a global variable or a function, prevents it from being used by any function that’s not defined in the same file. This is referred to as internal linkage. Static должны инициализироваться только константами, т.е. даже не const в с!

		int main ( void ) {
			auto int x = 5; // local variable to main (default as auto?)
			printf("local x in outer scope of main is %d\n", x );//5 
			{ // start new scope
				auto int x = 7; // local variable to new scope
				// When blocks are nested, and an identifier in an outer block has the same name as an identifier in an inner block, the identifier in the outer block is hidden until the inner block terminates. Просто x был бы доступен.
				printf( "local x in inner scope of main is %d\n", x );//7
			} // end new scope 
			printf( "local x in outer scope of main is %d\n", x );//5

			auto int first = 1, last = 2 ; 
			{
				printf("%d\n", a);//666
				extern int first, last;// This declaration uses the storage-class specifier extern to indicate that variable flag is defined either later in the same file or in a different file. The compiler informs the linker that unresolved references to variable flag appear in the file. If the linker finds a proper global definition, the linker resolves the references by indicating where flag is located. If the linker cannot locate a definition of flag, it issues an error message and does not produce an executable file. Any identifier that’s declared at file scope is extern by default. 
				printf("%d %d\n", first, last);//10 20 ; Because the extern declaration tells the compiler that first and last are declared elsewhere (in this case, later in the same file), the program can be compiled without error even though first and last are used prior to their definition.
				//It is important to understand that the extern variable declarations as shown in the preceding program are necessary only because first and last had not yet been declared prior to their use in main( ). Had their declarations occurred prior to main( ), there would have been no need for the extern statement. 
				//Remember, if the compiler finds a variable that has not been declared within the current block, the compiler checks whether it matches any of the variables declared within enclosing blocks(внешних блоках). If it does not, the compiler then checks the global variables. If a match is found, the compiler assumes that is the variable being referenced.
				//As mentioned, extern allows you to declare a variable without defining it. However, if you give that variable an initialization, the extern declaration becomes a definition. This is important because, as stated earlier, an object can have multiple declarations, but only one definition.

				//Just as extern declarations can be used to declare global variables to other program files, function prototypes can extend the scope of a function beyond the file in which it’s defined (the extern specifier is not required in a function prototype). Function prototypes indicate to the compiler that the specified function is defined either later in the same file or in a different file. Again, the compiler does not attempt to resolve references to such a function—that task is left to the linker. 
			}
			printf("%d %d\n", first, last);//1 2
			
			useLocal(); //25 26; useLocal has automatic local x 
			useStaticLocal(); //50 51; useStaticLocal has static local x 
			useGlobal(); //1 10; useGlobal uses global x
			useLocal(); //25 26; useLocal reinitializes automatic local x
			useStaticLocal(); //51 52; static local x retains its prior value
			useGlobal(); //10 100; global x also retains its value
			
			printf( "\nlocal x in main is %d\n", x );//5

			printf("var1 is %d\n", var1);//var is 111
			extern int var2;// When the linker links the two modules, all references to the external variables are resolved. 
			//Или можно закинуть extern int var2 в .h файл, в .с файле определить int var2, скомпилировать, линковать. 
			printf("var2 is %d\n", var2);//var2 is 222

			printf("var3 is %d\n", var3);//var3 is 333

			printf("max is %d\n", max() );//max is 123

			return 0;
		} 

		int first = 10, last = 20;// global definition of first and last 
		
		void useLocal( void ) {// useLocal reinitializes local variable x during each call
			auto int x = 25;
			printf( "\nlocal x in useLocal is %d after entering useLocal\n", x );
			++x;
			printf( "local x in useLocal is %d before exiting useLocal\n", x );
		} 

		void useStaticLocal( void ) {
			static int x = 50;// useStaticLocal initializes static local variable x only the first time the function is called; value of x is saved between calls to this function
			printf( "\nlocal static x is %d on entering useStaticLocal\n", x );
			++x;
			printf( "local static x is %d on exiting useStaticLocal\n", x );
			static int arr[5] = {1,2,3,4,5};//массив не будет всякий раз создаваться при вызове функции и уничтожаться после выхода из неё. Все тоже самое, что и с static переменными в примере про scope. static array автоматически инициализируется нулями, если не указано иное. static будет инициализирован нулями, но даже static int a[3]= {11,12,13}; не приведет к повторной инициализации. 
			++arr[1];
		} 

		void useGlobal( void )  {// function useGlobal modifies global variable x during each call
			printf( "\nglobal x is %d on entering useGlobal\n", x );
			x *= 10;
			printf( "global x is %d on exiting useGlobal\n", x );
		}

		//file1.c// 
		int var1 = 111;
		//file1.h// 
		int var1;

		//file2.c// gcc main.o file1.o
		int var2 = 222;

		//file3.c// 
		int var3 = 333;
		//file3.h// 
		extern int var3;

		//max.h
		static int max (void){//вместо помещения заголовка в .h файл (как обычно), функция помещается целиком в .h и потом вставляется во все файлы. Поскольку у этой функции внутренняя компоновка ни один из файлов не сделает имя max видимым извне. Так что все эти экземпляры останутся независимыми и не будут конфликтовать друг с другом.
			return 123;
		}

		

Type Qualifiers
	C defines type qualifiers that control how variables may be accessed or modified. C89 defines two of these qualifiers: const and volatile. (C99 adds a third, called restrict, which is described in Part Two.) The type qualifiers must precede the type names that they qualify.
	Remember, a variable of type const can be modified by something outside your program. For example, a hardware device may set its value. However, by declaring a variable as const, you can prove that any changes to that variable occur because of external events. 
	The modifier volatile tells the compiler that a variable’s value may be changed in ways not explicitly specified by the program. For example, a global variable’s address may be passed to the operating system’s clock routine and used to hold the system time. In this situation, the contents of the variable are altered without any explicit assignment statements in the program. This is important because most C compilers automatically optimize certain expressions by assuming that a variable’s content is unchanging if it does not occur on the left side of an assignment statement; thus, it might not be reexamined each time it is referenced. Also, some compilers change the order of evaluation of an expression during the compilation process. The volatile modifier prevents these changes.  
	For example, if 0x30 is assumed to be the value of a port that is changed by external conditions only, the following declaration would prevent any possibility of accidental side effects:
		const volatile char *port = (const volatile char *) 0x30;//см. указатели

	Restrict делает две вещи: гарантирует отсутствие повторного обращения к референту в ассемблерном коде, если в исходном коде рестрикт указатель не использовался для изменения значения референта, и своим существованием в прототипе говорит от необходимости неперекрывания референта другими объектами, вместо словесного описания, что поведение функции при перекрытии неопределено.  

Относительная адресация
	Первая команды функции, после ее добавки в какую-нибудь программу, может расположиться в любом адресе: что 1000, что 2000. 
	Если операнд инструкции перехода равен фиксированному значению, например, 20, то переход выполнится не вовнутрь нашей функции, приблизительно в 1020 или 2020, а просто по адресу 20. Такая ситуация происходит при абсолютной адресации.
	Чтобы это исправить используется относительная адресация. Ассемблер меняет коды команд для переходов (вроде call, @label и т.п.), а операнды таких команд из абсолютных адресов превращаются в смещения. Смещение равно числу инструкций от команды до нужного места. Эти смещения высчитывает ассемблер. 
	Процессор выполняет такую команду. Он складывает смещение с PC и выполняет переход по этому адресу. 

Variable-Length Argument Lists 
//Variable Length Parameter Lists, variable number of arguments
	#include <stdio.h>
	#include <stdarg.h>//The macros and definitions of the variable arguments headers <stdarg.h> provide the capabilities necessary to build functions with variable-length argument lists. 
	void average( int i, ... );//The ellipsis (…) in the function prototype indicates that the function receives a variable number of arguments of any type. The ellipsis must always be placed at the end of the parameter list.  
	int main( void ) {
		double w = 37.5;
		double x = 22.5;
		double y = 1.7;
		average( 1, w );
		average( 3, w, x, y ) ;
		return 0;
	} 
	void average( int i, ... ) {
		va_list ap;//A type suitable(пригодный) for holding information needed by macros va_start, va_arg and va_end. To access the arguments (чтобы получить доступ к аргументам) in a variable-length argument list, an object of type va_list must be defined. 
		va_start( ap, i );//A macro va_start that’s invoked before the arguments of a variable-length argument list can be accessed. The macro initializes the object declared with va_list for use by the va_arg and va_end macros. 
		//The macro va_start receives two arguments: object ap and i, the identifier of the rightmost argument in the argument list before the ellipsis (va_start uses i here to determine where the variable-length argument list begins).
		for ( int j = 1; j <= i; ++j ) {
		 printf ("%f ", va_arg( ap, double ) );//A macro va_arg that expands (раскрывается в) to the value of the next argument in the variable-length argument list. The value has the type specified as the macro’s second argument (тип значения определяется вторым аргументом макроса). Each invocation of va_arg modifies the object declared with va_list so that (так, что) it points to the next argument in the list. 
		 //Macro va_arg receives two arguments: object ap and the type of the value expected in the argument list — double in this case. The macro returns the value of the argument. 
		}
		printf ("\n"); 
		va_end( ap );//A macro va_end that facilitates (облегчает) a normal return from a function whose (чей) variable-length argument list was referred to by the va_start macro.
		//Function average invokes macro va_end with object ap as an argument to facilitate a normal return to main from average. 
		return;
	} 
	37.500000
	37.500000 22.500000 1.700000

Signal Handling
	#include <stdio.h>//printf();
	#include <stdlib.h>//exit()
	#include <signal.h>//SIGINT, signal(), raise()
	void signalHandler( int signalValue ); 
	int main( void ) {
		int i; int x;
		signal( SIGINT, signalHandler );//Function signal receives two arguments—an integer signal number (for example, SIGINT - receipt of an interactive attention signal, the standard signal defined in header file <signal.h> ) and a pointer to the signal-handling function. 
		//If specified signal occurs, function signal traps him and control passes (control is passed ?) to function signalHandler.
		for ( i = 1; i != 10; ++i ) {
			if ( i == 5 ) {
				raise( SIGINT );// Function raise takes an integer signal number as an argument and generates signal. 
				//Normally, SIGINTs are initiated outside the program. For example, typing <Ctrl> c during program execution on a Linux/UNIX or Windows system generates a SIGINT that terminates program execution. Signal handling can be used to trap the SIGINT and prevent the program from being terminated. 
			}
			printf( "%d\n", i );
		}
		return 0;
	}
	void signalHandler( int signalValue ) {
		int response;
		printf( "signalValue %d\n", signalValue );
		scanf( "%d", &response );
		while ( response != 1 && response != 2 ) {
			printf( "%s", "( 1 = yes or 2 = no )? " );
			scanf( "%d", &response );
		}
		if ( response == 1 ) {
			signal( SIGINT, signalHandler );//If the user wishes to continue execution, the signal handler is reinitialized by calling signal again and control returns to the point in the program at which the signal was detected.
		}
		else {
			exit( EXIT_SUCCESS );//Terminating program with function exit. В данном примере нет зарегестрированных функций с помощью atexit. If exit is called with EXIT_SUCCESS, the implementation-defined value for successful termination is returned to the calling environment. 
		}
		return;
	}

Unconditional Branching with goto
	#include <stdio.h>
	int main( void ){
		int count = 1;
		start: // Function labels consist of an identifier, followed by a colon.
		if ( count > 10 ) {
			goto end;
		} 
		printf( "%d ", count );
		++count;
		goto start; //  goto start on line 4
		end: // label
		putchar( '\n' );
		return 0;
	}

Разные функции
	Вывод с задержкой в секунду.
		#include <stdio.h>
		#include <stdlib.h> 
		#include <unistd.h> 
		int main ( void ){
			for(int i=0; i < 100; i++){
				system("cls");
				if( (i % 2) != 0){  
					for(int i=0; i<4; i++)
						printf("1111\n");
					sleep(1);
				}
				if( (i % 2) == 0){  
					for(int i=0; i<4; i++)
						printf("0000\n");
					sleep(1);
				}
			}
		}
		или так
		int main ( void ){
			for(int i=0; i != EOF; ){
				system("cls");
				for(int i=0; i<4; i++)
					printf("1111\n");
				sleep(1);
				system("cls");
				for(int i=0; i<4; i++)
					printf("0000\n");
				sleep(1);
			}
		}
	Секундомер
		#include <stdio.h>
		#include <time.h>
		int main ( void ){
			time_t i = 0; //
			while (1){
				if (i != time(NULL) ){
					i = time(NULL); 
					printf ("%d\n", i%60);
				}
			}
		}
	Перевод в двоичную систему.
		#include <stdio.h>
		void foo (int x){
			int ZOP[8]={0};//8 разрядов.
			int i = 0;
			while ( x != 0){
				ZOP[i]= x % 2 ;
				x = x / 2 ;//1 / 2 равен 0.
				if (x == 0)
					break;
				i=i+1;
			}
			while ( i >= 0){
				printf("%d", ZOP[i]);
				i = i-1;
			}
		}
	стало
		void foo (int x){
			int ZOP[32]={0};//32 разряда. И зачем целый массив...
			int i;
			for (i = 0; x != 0; ++i){
				ZOP[i]= x % 2 ;
				x = x / 2 ;// 1 / 2 равен 0.
			}
			for ( --i ; i >= 0; --i){
				printf("%d", ZOP[i]);
			}
		}
	лол
		void foo (int n){
			while(n) {
				printf("%d", n%2);
				n /= 2;
			}
		}
	Количество разрядов числа v1.
		int NumberOfDigits1 (int number){
			int digit = 0;
			for ( int devisor = 1 ; (number % devisor) != number ; devisor*=10 ) {
				++digit;
			}
			return digit;
		}
	Количество разрядов числа v2. М, четко.
		int NumberOfDigits2 (int n) 
		{
			int i = 1;
			if (n < 0) 
			{
				n = -n;
			}
			while ( (n = n/10) != 0) 
			{
				++i;
			}
			return i;
		}
	Количество символов числа 3 с учетом знака
		#include <stdlib.h>
		int NumberOfSymbols1 (int n) {//-45
			n = snprintf(NULL, 0, "%d", n) ;//3
			return n;
		}
	Степень числа 1
		int IntegerPower1 (int a, int b ){//a^b
			int buffer = a;//=1 lol
			if ( b == 0) {
				buffer = 1;
			}
			else{
				while ( b != 1 ) {//!=0 lol
					buffer *= a;
					--b; 
				}
			}
			return buffer;
		}
	Степень числа 2.
		double IntegerPower2 (double x, long n) {//from https://ru.wikibooks.org , not mine, I'd make it rude.
			double a = 1;
			while(n) {
				if(n % 2) {//if n is odd
					a *= x;
					n--;
				}
				else{	//if n is even
					x *= x;
					n /= 2;    
				}
			}
			return a;
		}
	Поразрядное использование числа 
		//Чтобы преобразовывать в цифры + '0'
		void foo ( int number ){//foo(23562)
			int i = IntegerPower1 ( 10, NumberOfDigits1(number) - 1 );//степень 10 (10000, 1000,100,10,1)
			while (i != 0) {
				printf ("%d ", number / i );//2 3 5 6 2
				number = number % i;
				i /= 10;
			}
		}
	Метод Эйлера википедия
		double func(double x, double y){
			return 6*x*x+5*x*y; // функция первой производной
		}
		int main(int argc, char** argv){
			int i, n; 
			double x, y, h;
			h = 0.01; // шаг
			n = 10; // количество итераций
			x = 1; // x0
			y = 1; // y0
			for (i = 0; i < n; i++){
				y += h * func(x, y); // вычисление yi
				x += h;
			}
			return EXIT_SUCCESS;
		}
	Стохастическая игра
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>
		int main ( void ){
			int x, y, z=0, sum;
			srand( time(NULL) );
			x = rand () % 6 +1;
			y = rand () % 6 +1;
			sum = x + y;    
			switch (sum){
				case 7 : case 11 :
					printf("x=%d y=%d\n", x, y);
					puts ("Win: 7 or 11");
					break;
				case 2 : case 3 : case 12 : 
					printf("x=%d y=%d\n", x, y);
					puts ("Lose: 2, 3 or 12");
					break;
				default : // 4,5,6,8,9,10
					printf("x=%d y=%d\n", x, y);
					puts("First lose! Again!");
					getchar();

					while (z==0){
						x = rand () % 6 +1;
						y = rand () % 6 +1;
						if (x + y == sum){ //if x + y == 4,5,6,8,9,10
							printf("x=%d y=%d\n", x, y);
							puts ("Win: x+y=first sum");
							z=1;
						}
						if (x + y == 7){
							printf("x=%d y=%d\n", x, y);
							puts ("Lose: 7");
							z=1;
						}   
						else{//удобно отсутствием условий
							printf("x=%d y=%d\n", x, y);
							puts ("Again: x+y!=first sum");
							getchar();
							//z=0;
						}
					}
					break;
			}
			return 0;
		}   

Passing Arrays to Functions
	Вывод многомерного массива и передача в функцию.
	Передача строки массива как одномерного массива в функцию. Упрощенная версия fig06_22.c . 
	Variable-Length Arrays VLA. 
	ВЛА убраны из Си и запрещены в студии. Но в плюсах можно задавать размеры с помощью константных переменных.
	Во всех предыдущих примерах массивы задавались константами (в том числе и через define). А здесь суть в объявлении размера массива уже после запуска программы. Именно для этого в индексах используют переменные, которые можно инициализировать в коде или получить от пользователя.
		#include <stdio.h>
		void print1DArray( int size, int array[size] );
		void print2DArray( int row, int col, int array[row][col] );
		int main ( void )   
		{
			int x, row1, col1;
			x = 5;
			row1 = 2;
			col1 = 3;
			int d1 [x];//Размер указывает переменная. 
			int d2 [row1][col1];//С многомерными все тоже самое.
			
			for ( int i = 0; i < x; ++i ) 
			{
				d1[i] = i * i;
			} 

			for ( int i = 0; i < row1; ++i ) 
			{
				for ( int j = 0; j < col1; ++j ) 
				{
					d2[i][j] = i + j;
				}
			}

			print1DArray( x, d1 );//Все передается точно так же, как и во всех предыдущих примерах. Разве что сначала идет переменная, а потом массив.
			//Теперь передача переменных в списке параметров функций необходима, ведь это теперь не заранее известные константы!
			print2DArray( row1, col1, d2 );

		}

		void print1DArray( int size, int array[size] )//[size] используется здесь исключительно в целях документирования кода для других программистов.
		//сначала объявить size, чтобы можно было его использовать в int array [size]; 
		{
			for ( int i = 0; i < size; i++ ) 
			{
				printf( "%4d", array[ i ] );
			}
			puts ("");
		}

		void print2DArray( int row, int col, int array[row][col] )//col будет удовлетворять требованию указывать все индексы, кроме первого! 
		{
			for ( int i = 0; i < row; ++i ) 
			{
				for ( int j = 0; j < col; ++j ) 
				{
					printf( "%4d", array[ i ][ j ] );
				}
			}
			puts ("");
		}

Pointer to Function. 
	A pointer to a function contains the address of the function in memory. In Chapter 6, we saw that an array name is really the address in memory of the first element of the array. Similarly (аналогично), a function name is really (в действительности) the starting address in memory of the code that performs the function’s task. Pointers to functions can be passed to functions, returned from functions, stored in arrays and assigned to other function pointers. 
		#include <stdio.h>
		int   ascending ( int a, int b ) ;
		int * somefoo   ( int x, int y ) ;// declares a function that receives two integers as parameters and returns a pointer to an integer.
		int main ( void )   
		{
			int (*FunctionPtr) (int x, int y);//FunctionPtr that’s a pointer to a function that receives two integer parameters and returns an integer result.

			// The "Clockwise/Spiral Rule"
			// char *(*fp)( int, float *);
			     +--------------------+
			     | +---+              |
			     | |+-+|              |
			     | |^ ||              |
			char *(*fp) ( int, float *);
			 ^   ^ ^  ||              |
			 |   | +--+|              |
			 |   +-----+              |
			 +------------------------+
			// fp is a pointer to a function passing an int and a pointer to float returning a pointer to a char
			
			printf ("%d\n", ascending(7,2) );//ничего интересного.
			FunctionPtr = ascending; 
			printf ("%d\n", (*FunctionPtr)(7,2) );//Just as a pointer to a variable is dereferenced to access the value of the variable, a pointer to a function is dereferenced to use the function; указатель выступает как посредник, который передает полученные значения. 
			// printf ("%d\n", FunctionPtr(7,2) );//можно, но через разыменование нагляднее, чтобы не перепутать с функцией.
		}
		int ascending( int a, int b ) 
		{
			return b - a;
		}

	Указатель на функцию в параметрах функции. Все тоже самое, что и в примере выше. bubble получает адрес функции, после чего сама же передает значения в эту функцию.
		#include <stdio.h>
		void bubble ( int (*FunctionPtr)(int x, int y) );
		int ascending( int a, int b );
		int descending( int c, int d );
		int main ( void ) {
			bubble( ascending );
			bubble( descending );
		}
		void bubble ( int (* FunctionPtr)(int x, int y) )   {
			printf ("%d\n", (*FunctionPtr)( 7 , 2 ) );
		}
		int ascending( int a, int b ) {
			return b - a;
		}
		int descending( int c, int d )  {
			return c + d;
		}

	Универсальная программа сортировки, использующая указатели на функции.
		#include <stdio.h>
		#define SIZE 10
		void bubble( int work[], size_t size, int (* FunctionPtr)( int x, int y ) );
		int ascending( int a, int b );
		int descending( int a, int b );
		int main ( void )   {
			int order ; // 1 - for ascending order, 2 –for descending order
			int a[ SIZE ] = { 10, 4, 6, 8, 2, 12, 89, 68, 45, 37 };
			for ( size_t counter = 0; counter < SIZE; ++counter ) {
				printf( "%3d", a[ counter ] ); 
			}
			puts ("");
			scanf ( "%d", &order );
			if ( order == 0 ) {
				bubble( a, SIZE, ascending );//pass function ascending;
			}
			else {
				bubble( a, SIZE, descending );//pass function descending.
			}
			for ( size_t counter = 0; counter < SIZE; ++counter ) {
				printf( "%3d", a[ counter ] );
			}
		}
		void bubble ( int work[], size_t size, int (* FunctionPtr)(int x, int y) ) {
			void swap( int * element1Ptr, int * element2Ptr );//просто прототип swap.
			for ( int pass = size-1 ; pass != 0; --pass )   {
				for ( int count = 0; count != pass; ++count )   {
					if ( (*FunctionPtr) ( work[count], work[count+1] ) == 0 ) {
					//Передача элементов в функцию асендин или десендин с помощью указателя FuctionPtr. 
					//Если функция вернет 1, то все в порядке; 1 == 0 даст 0.
					//Если функция вернет 0, то нужен своп; 0 == 0 даст 1. Тогда будет вызван своп, чтобы поменять элементы местами.
						swap( &work[count], &work[count+1] );//передача элементов в своп.
					}
				}
			}
		}
		int ascending( int a, int b )   {
			return b > a;//Ассендин вернет 1, если следующее больше предыдущего; то есть если все в порядке. 
		}
		int descending( int a, int b ) {
			return b < a;//Дессендин вернет 1, если следующее меньше предыдущего.
		}
		void swap( int * element1Ptr, int * element2Ptr ) {
			int hold;
			hold = *element1Ptr;
			*element1Ptr = *element2Ptr;
			*element2Ptr = hold;
		}

	Demonstrating an array of pointers to functions. 
	Бонус в отказе от свичей с кейсами? Тогда понятно, почему непонятен указатель на функцию и понятно когда массив указателей на функции. Нет, бонус в том, что чужие функции могут иметь любые имена. Наша функция уже может быть сделана, пока другие программисты не закончили делать свои или даже не определились с названиями. А наша функция будет принимать указатель на массив указателей на функции. 
		#include <stdio.h>
		void select ( void ( *fPtr [] )(int) ) ;
		// void select ( void (**fPtr)(int) );
		void function1( int a );
		void function2( int b );
		void function3( int c );
		int main ( void )   
		{
			void ( *AoPtF [] )( int ) = { function1, function2, function3 };// Имя параметра давать необязательно, логично?
			//AoPtF is an array of pointers to a function passing an int returning void.
			select (AoPtF);

			// 	Или еще вариант
			// 	#include <stdio.h>
			// 	void foo(int a)
			// 	{
			// 		printf("%d", a);
			// 	}
			// 	int main(void)
			// 	{
			// 		void (*AoPtF[10])(int) = { NULL };
			// 		AoPtF[1] = foo;
			// 		(*foo)(5);
			// 		return 0;
			// 	}
		}
		void select ( void ( *fPtr[] )(int) ) {
		// void select ( void (**fPtr)(int) ){
			int choice = 0;
			while (choice != -1){
				scanf ( "%d", &choice );
				(*fPtr[ choice ])( choice );//In the function call, fPtr[choice] selects the pointer at location choice in the array (извлекает указатель на функцию из элемента с индексом choice в массиве). The pointer is dereferenced to call the function, and choice is passed as the argument to the function.
			}
			puts( "Program execution completed." );
		}
		void function1( int a ) {
			printf( "You entered %d so function1 was called\n", a );
		}
		void function2( int b ) {
			printf( "You entered %d so function2 was called\n", b );
		} 
		void function3( int c ) {
			printf( "You entered %d so function3 was called\n", c );
		} 

C Structures, Unions, Bit Manipulation and Enumerations.
	Structures—sometimes referred to as aggregates—are collections of related variables under one name. Structures may contain variables of many different data types—in contrast to arrays, which contain only elements of the same data type. Structures (почему не дописали data types?) are derived data types—they’re constructed using objects of other types. 

		struct card //Keyword struct introduces a structure definition. 
		//The identifier card is the structure tag, which names the structure definition and is used with struct to declare variables of the structure type—e.g., struct card. 
		{
			char * face;//Variables declared within the braces of the structure definition are the structure’s members. 
			char * suit;
			char firstName[ 20 ];
			double hourlySalary;
			//ER  struct card person;//A structure cannot contain an instance of itself. 
			struct card * person;//A structure containing a member that’s a pointer to the same structure type is referred to as a self-referential structure. 
		};//Structure definitions do not reserve any space in memory; rather, each definition creates a new data type that’s used to define variables.
		struct card aCard, deck [ 52 ], * cardPtr;//Structure variables are defined like variables of other types. The definition declares aCard to be a variable of type struct card, declares deck to be an array with 52 elements of type struct card and declares cardPtr to be a pointer to struct card. Variables of a given structure type may also be declared by placing a comma-separated list of the variable names between the closing brace of the structure definition and the semicolon that ends the structure definition.

		struct {//The structure tag name is optional. If a structure definition does not contain a structure tag name, variables of the structure type may be declared only in the structure definition—not in a separate declaration.
		 char name [30];
		 char street [40];
		 char city [20];
		 char state [3];
		 unsigned long int zip;
		} addr_info;

	Operations That Can Be Performed on Structures. 
	The only valid operations that may be performed on structures are:
		assigning structure variables to structure variables of the same type 
		taking the address (&) of a structure variable 
		accessing the members of a structure variable (see Section 10.4) 
		using the sizeof operator to determine the size of a structure variable. 

		#include <stdio.h>
		struct simple {
			int a;
			int b;
			int * c;
		};
		struct card {
			char * face;
			char * suit;
			char MAS [30];
			int zip;
		};
		int main( void ) {
			struct simple BBB = {1,2} ;
			printf ("%d %d\n", BBB.a , BBB.b );//1 2

			struct card aCard = { "Three", "Hearts" };//Define one struct card variable. 
			//The declaration creates variable aCard to be of type struct card and initializes member face to "Three" and member suit to "Hearts". If there are fewer initializers in the list than members in the structure, the remaining members are automatically initialized to 0 (or NULL if the member is a pointer). Structure variables defined outside a function definition (i.e., externally) are initialized to 0 or NULL if they’re not explicitly initialized in the external definition. Structure variables may also be initialized in assignment statements by assigning a structure variable of the same type, or by assigning values to the individual members of the structure.
			printf( "%p %p\n", &aCard, aCard );//0028FF00 0040B064
			printf( "%p %s\n", aCard.face, aCard.face );//0040B064 Three ; The structure member operator accesses a structure member via the structure variable name. 
			printf( "%p %s\n", aCard.suit, aCard.suit );//0040B06A Hearts
			
			struct card * cardPtr = &aCard;//the pointer cardPtr has been declared to point to struct card and that the address of structure aCard has been assigned to cardPtr. Pointer cardPtr is assigned the address of structure aCard (указателю присваивается адрес).
			printf( "%p %p\n", &cardPtr, cardPtr );//0028FEFC 0028FF00
			printf( "%p %p\n", cardPtr, *cardPtr );//0028FF00 0040B064
			printf( "%p %s\n", (*cardPtr).face, (*cardPtr).face );//0040B064 Three ; The parentheses are needed here because the structure member operator (.) has a higher precedence than the pointer dereferencing operator (*). 
			printf( "%p %s\n", cardPtr->face, cardPtr->face );//0040B064 Three ; The structure pointer operator accesses a structure member via a pointer to the structure.
			//The structure pointer operator and structure member operator, along with parentheses (for calling functions) and brackets ([]) used for array subscripting, have the highest operator precedence and associate from left to right. 
			
			struct card x, y;
			x.zip = 12345;
			y = x;
			printf("%p %d\n", &( y.zip ), y.zip );//0028FECC 12345
			y.MAS[0] = 'G';
			//ER  printf("%p\n", &(y.MAS) );
			printf("%p %c %p\n", &( y.MAS[0] ), y.MAS[0], y.MAS );//0028FEAC G 0028FEAC 

			fgets( &( y.MAS[0] ), 30, stdin );//hello ; fgets нужен адрес.
			//fgets( y.MAS, 30, stdin );
			for(int t=0 ; y.MAS[t] ; ++t) {
				putchar( y.MAS[t]) ;//hello
			}
			return 0;   
		}

	Sometimes there are “holes” in a structure, because computers may store specific data types only on certain memory boundaries (определенных границах памяти) such as half-word, word or double-word boundaries. A word is a standard memory unit used to store data in a computer—usually 2 bytes or 4 bytes. 
		#include <stdio.h>
		int main( void ) {
			struct card {
				char * ptr1;
				short * ptr2;
				char a;
				short b;
			};
			struct card deck ;
			printf ("%d\n", sizeof ( char )         );//1 
			printf ("%d\n", sizeof ( short )        );//2
			printf ("%d\n", sizeof ( deck )         );//16
			printf ("%d\n", sizeof ( deck.ptr1 )    );//4
			printf ("%d\n", sizeof ( deck.ptr2 )    );//4
			printf ("%d\n", sizeof ( deck.a )       );//1
			printf ("%d\n", sizeof ( deck.b )       );//2
			printf ("%d\n", sizeof ( *(deck.ptr1) ) );//1
			printf ("%d\n", sizeof ( *(deck.ptr2) ) );//2
			return 0;       
		}
		struct test{
			char a;
			char c;
			int b;
			int n;
		};
		0028FF28 a00000000
		0028FF29 c00000000
		0028FF2A
		0028FF2B
		0028FF2C b00000000
		0028FF2D
		0028FF2E
		0028FF2F
		0028FF30 n00000000
		0028FF31
		0028FF32
		0028FF33
		struct test{
			char a;
			int b;
			char c;
			int n;
		};
		0028FF28 a00000000
		0028FF29
		0028FF2A
		0028FF2B
		0028FF2C b00000000
		0028FF2D
		0028FF2E
		0028FF2F
		0028FF30 c00000000
		0028FF31
		0028FF32
		0028FF33
		0028FF34 n00000000
		0028FF35
		0028FF36
		0028FF37
	
	Designated initializers (after -std=C99)
	#include <stdio.h>
	int main() {
		int arr[5] = {
			[1] = 1,
			[4]	= 4,
		};
		struct Point {
			int x;
			int y;
		};
		struct Point dot1 = {
			.x = 1,
			.y = 2,
		};

		printf("%d ", arr[3]);
		printf("%d ", dot1.y);
		return 0;
	}

Using Structures with Functions. 
	When structures or individual structure members are passed to a function, they’re passed by value. Therefore, the members of a caller’s structure cannot be modified by the called function. In Chapter 6, we stated that an array could be passed by value by using a structure. To pass an array by value, create a structure with the array as a member. Structures are passed by value, so the array is passed by value.
	To pass a structure by reference, pass the address of the structure variable(by passing a pointer to a structure). 
	Arrays of structures—like all other arrays—are automatically passed by reference. 

typedef
	The keyword typedef provides a mechanism for creating synonyms (or aliases) for previously defined data types. Names for structure types are often defined with typedef to create shorter type names. 

		typedef int Integer;
		Integer x = 2; 
		printf ("%d %d %d\n", sizeof(Integer), sizeof(x), x);//4 4 2

		typedef int * intptr;
		intptr a, b;// int * a, * b;
			
		struct card {
			const char *face;
			const char *suit;
		} ;
		typedef struct card Card;//defines the new type name Card as a synonym for type struct card
		// имя может быть таким же, 6.2.3
		int main( void ) {
			Card deck [CARDS];
		}

		typedef struct {
			const char *face;
			const char *suit;
		} Card;// Это уже не имя структурной переменной. C programmers often use typedef to define a structure type, so a structure tag is not required. For example, the following definition creates the structure type Card without the need for a separate typedef statements. typedef не тоже самое, что простая замена через макросы. Две безымянные, но одинаковые внутри структуры, имеют разный тип. Тайпдеф позволяет избавиться от этой проблемы и объявлять структурные переменные точно так же, как и объекты класса в с++, а именно без написания ключевого слова struct (аналогично ненаписанию слова class).
		int main( void ) {
			Card deck [CARDS];
		}

	fig07_24.c
		#include <stdio.h>
		#include <stdlib.h>
		#define SUITS 3
		#define FACES 5
		#define CARDS 15
		void shuffle( int wDeck [][ FACES ] );
		void prnt( int wDeck [][ FACES ] );
		void deal( int wDeck [][ FACES ] ); 
		int main ( void ) {
			int wDeck [SUITS][FACES] = {0};// Каталог карт, где каждой карте присвоено значение, которое является порядковым номером в колоде. Естественнее было бы заменить на колоду, то есть массив карт в виде "масть, значение","масть, значение" и т.д..
			shuffle( wDeck );
			prnt( wDeck );
			deal (wDeck);
			return 0;
		}
		void shuffle( int wDeck [][ FACES ] ){
			int row, column, number;
			for (number = 0; number != CARDS; ++number) {
				do {
					row = rand() % SUITS;
					column = rand() % FACES;
				} while( wDeck[ row ][ column ] != 0 ); 
				wDeck[ row ][ column ] = number;
			}
			return;
		}   
		void prnt( int wDeck [][ FACES ] ){
			int row, column;
			for (row = 0; row != SUITS; ++row) {
				for (column = 0; column != FACES; ++column) {
					printf ("%d ", wDeck[row][column] );
				}
				puts ("");
			}
			return;
		}
		void deal( int wDeck [][ FACES ] ){
			int row, column, number;
			for (number = 0; number != CARDS; ++number) {// Поиск каждого number последовательно во всех элементах каталога.
				for (row = 0; row != SUITS; ++row ) {
					for (column = 0; column != FACES; ++column) {
						if ( wDeck[row][column] == number) {
							printf ("%d  %d %d\n", wDeck[row][column], row, column );// row и column можно использовать в качестве индексов массивов указателей на строки.
						}
					}
				}
			}
			return;
		}
	fig10_03.c
		#include <stdio.h>
		#include <stdlib.h>
		#define FACESquantity 4
		#define CARDSquantity 12

		typedef struct 
		{
			const char * face;
			const char * suit;
		} CardTemplate;

		void fillDeck( CardTemplate * const deck, const char * faces [], const char * suits [] );
		void shuffle( CardTemplate * const deck );
		void deal( const CardTemplate * const deck );

		int main( void ) 
		{
			CardTemplate deck [CARDSquantity] ;// Колода карт
			const char * faces [] = { "One", "Two", "Three", "Four"};
			const char * suits [] = { "Hearts", "Diamonds", "Clubs"};
			fillDeck( &deck[0] , &faces[0] , &suits[0] );
			shuffle( &deck[0] );
			deal( &deck[0] );
		} 
		void fillDeck( CardTemplate * const deck, const char * faces [], const char * suits [] ) {
			for ( size_t number = 0; number != CARDSquantity; ++number ) {
				deck[number].face = faces[number % FACESquantity];// % 5 дает от 0123401234...
				deck[number].suit = suits[number / FACESquantity];// / 5 дает 000001111122222...
			}
		}
		void shuffle( CardTemplate * const deck ) {
			size_t j; // Переменная для хранения случайного числа 0-51
			CardTemplate temp; // Временная структура для обмена карт местами
			for ( size_t number = 0; number != CARDSquantity; ++number ) {
				temp = deck[number];// бэкап deck[number]
				j = rand() % CARDSquantity;// % 15 дает случайные от 0 до 14 , а если даст одинаковые?
				deck[number] = deck[j];// замена содержимого deck[number] на содержимое deck[j]
				deck[j] = temp;// замена содержимого deck[j] на бэкап
			} 
		}
		void deal( const CardTemplate * const deck ) {
			for ( size_t number = 0; number != CARDSquantity; ++number ) {
				printf( "%-5s %-10s %s", 
					deck[number].face, deck[number].suit, 
					( number + 1 ) % 2 ? " " : "\n" );//number 1,3,5,7 будут давать ноль. if в printf.
			}
		}

Unions 
	A union is a derived data type—like a structure—with members that share the same storage space. The union definition is normally placed in a header and included in all source files that use the union type. 

		union u_type {
		 int i;
		 char ch;
		};
		union u_type cnvt;
		|<-------+------- i -------+--------|
		|                 |                 |
		+--------+--------+--------+--------+
		| Байт 0 | Байт 1 | Байт 2 | Байт 3 |
		+--------+--------+--------+--------+
		|        |
		|<- ch --|

		#include <stdio.h>
		union number1 {
			int x;
			float y;
		};
		union number2 {
			float y;
			int x;
		};
		int main( void ){
			union number1 value1 = { 3 };
			printf( "%d %f \n", value1.x, value1.y );//3 0.000000
			value1.x = 99;
			printf( "%d %f \n", value1.x, value1.y );//99 0.000000
			value1.y = 99.5;
			printf( "%d %f \n", value1.x, value1.y );//1120337920 99.500000
			union number2 value2 = { 1.234 };
			//union number2 value2 = { 1.234, 2};// Ошибка
			printf( "%d %f \n", value2.x, value2.y );//1067316150 1.234000      
		}
		
Bit Fields
	C enables you to specify the number of bits in which an unsigned int or int member of a structure or union is stored. This is referred to as a bit field. Bit fields enable better memory utilization by storing data in the minimum number of bits required. Bit field members must be declared as int or unsigned int. Тип битового поля может быть int, signed или unsigned. (Кроме того, в соответствии со стандартом С99, у битового поля еще может быть тип _Вооl.) 
	Attempting to take the address of a bit field (the & operator may not be used with bit fields because they do not have addresses).

		#include <stdio.h>
		int main( void )
		{
			struct test {//Structure definition contains three unsigned int bit fields—face, suit and color.
				unsigned int face : 3;// 3 бита; 0-7
				//A bit field is declared by following an unsigned int or int member name with a colon (:) and an integer constant representing the width of the field (i.e., the number of bits in which the member is stored). The constant representing the width must be an integer between 0 and the total number of bits used to store an int on your system, inclusive. Our examples were tested on a computer with 4-byte (32-bit) integers. 
				unsigned int suit : 2;// 2 бита; 0-3
				unsigned int color : 2; // 2 бит; 0-3
				signed int z : 3;
			};
			typedef struct test Card;
			Card deck;
			//ER deck.color = 4;
			deck.color = 3;
			deck.suit = 3;
			deck.face = deck.color + deck.suit ;
			printf( "%d\n", deck.face );
			//6
			deck.face = deck.color * deck.suit ;
			printf( "%d\n", deck.face );
			//1

			deck.z = 0;
			for ( int i = 0 ; i != 9 ; ++i ) 
			{
				deck.z += 1;
				printf ("%d\n", deck.z);
			}		
			// 1
			// 2
			// 3
			// -4
			// -3
			// -2
			// -1
			// 0
			// 1
			return 0;
		}

	Another example.
		#include <stdio.h>
		#define CARDSquantity 32
		struct bitCard {
			unsigned int face : 3;// 3 бита; 0-7
			unsigned int suit : 2;// 2 бита; 0-3
			unsigned int color : 1; // 1 бит; 0-1
		};
		typedef struct bitCard Card;
		int main( void ){
			Card deck[ CARDSquantity ];
			size_t i;
			for ( i = 0; i != CARDSquantity; ++i ) {//fig10_03.c / % . CARDSquantity 32, i_max = 31 cause i = 0; i != 32.
				deck[ i ].face =    i%( CARDSquantity/4 )   ;//Значение face должно укладываться в 3 бита, max (i % (32/4)) = max( 31 % 8 ) = 7. 7 = 0b111 
				deck[ i ].suit =    i/( CARDSquantity/4 )   ;//Значение suit должно укладываться в 2 бита, max (i / (32/4)) = max( 31 / 8 ) = 3. 3 = 0b11 
				deck[ i ].color =   i/( CARDSquantity/2 )   ;//Значение color должно укладываться в 1 бит, max (i / (32/2)) = max( 31 / 16 ) = 1. 1 = 0b1.
			}
			for ( i = 0; i != CARDSquantity ; ++i ) {
				printf( "%d %d %d \n",
					deck[i].face, deck[i].suit, deck[i].color );
				if ( (i+1) % 8 == 0 ) {
					putchar( '\n' );
				}
			}
			return 0;
		} 

	The structure definition uses an unnamed 19-bit field as  padding—nothing can be stored in those 19 bits. Member b (on our 4-byte-word computer) is stored in another storage unit. 
		struct example {
		 unsigned int a : 13;
		 unsigned int   : 19;//unnamed bit field
		 unsigned int b : 4;
		};

	An unnamed bit field with a zero width is used to align the next bit field on a newstorage-unit boundary. For example, the structure definition uses an unnamed 0-bit field to skip the remaining bits (as many as there are) of the storage unit in which a is stored and to align b on the next storage-unit boundary.
		struct example {
		 unsigned int a : 13;
		 unsigned int   : 0;//an unnamed 0-bit field
		 unsigned int   : 4;
		};

Enumeration.
	???	
		#include <stdio.h>
		enum Emonths {
			JAN = 1, FEB, MAR, APR, MAY, JUN, JUL=100, AUG, SEP, OCT, NOV, DEC
		}; 
		int main( void ){
			printf ("%d\n", JAN) ;//1
			printf ("%d\n", FEB) ;//2
			printf ("%d\n", JUL) ;//100
			printf ("%d\n", AUG) ;//101
			
			enum Emonths month;
			month = FEB;
			
			const char *monthName[] = { "", "January", "February", "March",
				"April", "May", "June", "July", "August", "September", "October",
				"November", "December" };
			for ( month = JAN; month <= JUN; ++month ) {// JUN из-за JUL=100
				printf( "%2d%11s\n", month, monthName[ month ] );
			}
			return 0;
		}
	
	An enumeration, introduced by the keyword enum, is a set of integer constants represented by identifiers. Enumeration constants are sometimes called symbolic constants. Values in an enum start with 0 and are incremented by 1. The constant CONTINUE has the value 0, WON has the value 1 and LOST has the value 2. It’s also possible to assign an integer value to each identifier in an enum (see Chapter 10; WON = 34,). The identifiers in an enumeration must be unique, but the values may be duplicated. 
		#include <stdio.h>
		enum Status { CONTINUE, WON, LOST };//a programmer-defined type called an enumeration. 
		int main ( void )
		{
			enum Status gameStatus; // Variable gameStatus, defined to be of a new type — enum Status — stores the current status. 
			printf("%d\n", CONTINUE );//0
			printf("%d\n", WON );//1
			printf("%d\n", LOST );//2
			printf("%d\n", gameStatus );//
			
			gameStatus = WON; 
			printf("%d\n", gameStatus );//1
		}

Standard Input, Standard Output and Standard Error Streams
	???
	Most C programs input and/or output data. Certain C functions take their input from stdin (the standard input stream), which is normally the keyboard, but stdin can be connected to another stream. Data is often output to stdout (the standard output stream), which is normally the computer screen, but stdout can be connected to another stream. When we say that a program prints a result, we normally mean that the result is displayed on a screen. Data may be output to devices such as disks and printers. There’s also a standard error stream referred to as stderr. The stderr stream (normally connected to the screen) is used for displaying error messages. It’s common to route regular output data, i.e., stdout, to a device other than the screen while keeping stderr assigned to the screen so that the user can be immediately informed of errors.

Streams
	All input and output is performed with streams, which are sequences of bytes. In input operations, the bytes flow from a device (e.g., a keyboard, a disk drive, a network connection) to main memory. In output operations, bytes flow from main memory to a device (e.g.,a display screen, a printer, a disk drive, a network connection, and so on). 
	When program execution begins, three streams are connected to the program automatically. Normally, the standard input stream is connected to the keyboard and the standard output stream is connected to the screen. Operating systems often allow these streams to be redirected to other devices. A third stream, the standard error stream, is connected to the screen. We’ll show how to output error messages to the standard error stream in Chapter 11, C File Processing. Streams are discussed in detail in Chapter 11.

Files and Streams
	C views each file simply as a sequential stream of bytes (Fig. 11.1). Each file ends either with an end-of-file marker or at a specific byte number recorded in a system-maintained, administrative data structure. When a file is opened, a stream is associated with it. Three files and their associated streams are automatically opened when program execution begins—the standard input, the standard output and the standard error. Streams provide communication channels between files and programs. For example, the standard input stream enables a program to read data from the keyboard, and the standard output stream enables a program to print data on the screen. Opening a file returns a pointer to a FILE structure (defined in <stdio.h>) that contains information used to process the file. In some operating systems, this structure includes a file descriptor, i.e., an index into an operating system array called the open file table. Each array element contains a file control block (FCB)—information that the operating system uses to administer a particular file. The standard input, standard output and standard error are manipulated using file pointers stdin, stdout and stderr.
	The standard library provides many functions for reading data from files and for writing data to files. Function fgetc, like getchar, reads one character from a file. Function fgetc receives as an argument a FILE pointer for the file from which a character will be read. The call fgetc( stdin ) reads one character from stdin—the standard input. This call is equivalent to the call getchar().
	Function fputc, like putchar, writes one character to a file. Function fputc receives as arguments a character to be written and a pointer for the file to which the character will be written. The function call fputc( 'a', stdout ) writes the character 'a' to stdout—the standard output. This call is equivalent to putchar( 'a' ). 

C Formatted Input/Output. 
	
	9.3 Formatting Output with printf
	Precise output formatting is accomplished with printf. Every printf call contains a format control string that describes the output format. The format control string consists of conversion specifiers (see Fig. 5.5 Arithmetic data types and their conversion specifications), flags, field widths, precisions and literal characters. Together with the percent sign (%), these form conversion specifications.
	
	The printf function has the form
		printf("%[flags][width][.precision][length]specifier", other-arguments );
	format-control-string describes the output format, and other-arguments (which are optional) correspond to each conversion specification in format-control-string. Each conversion specification begins with a percent sign (%) and ends with a conversion specifier. There can be many conversion specifications in one format control string. 
		#include <stdio.h>
		int main( void ) 
		{
			printf("%.5g\n",123456789.2 );//1.23457e+008
			printf("%.6g\n",123456789.2 );//1.23457e+008
			printf( "%g\n", 123456789.2 );//1.23457e+008
			printf( "%g\n", 1234567.892 );//1.23457e+006
			printf( "%g\n", 123456.7892 );//123457
			printf( "%g\n", 12345.67892 );//12345.7
			printf( "%g\n", 12.34567892 );//12.3457
			printf( "%g\n", 1.234567892 );//1.23457
			printf( "%g\n", 0.123456789 );//0.123457
			printf( "%g\n", 0.000001234 );//1.234e-006

			printf("%10.3s\n", "abcdefg");//       abc
			char M[10] = {0};
			scanf ("%2s", &M[0] );//abcdef
			printf("%s\n", M );//ab

			printf( "\\ %% \n");//\ %  
			printf( "%p\n", 16);//00000010; %p Display a pointer value in an implementation-defined manner.
			printf ("%#x\n", 16);//0x10; %x Display as an unsigned hexadecimal integer; # display prefix
			
			printf("%04X\n", 0xF );//000F
			printf("%04d\n", 35  );//0035

			printf( "%.3f\n", 123.94536 );//123.945
			printf( "%.4f\n", 123.94536 );//123.9454
			printf( "%.3e\n", 123.94536 );//1.239e+002
			printf( "%.4e\n", 123.94536 );//1.2395e+002
			printf( "%.3g\n", 123.94536 );//124
			printf( "%.4g\n", 123.94536 );//123.9

			printf( "%*.*f", 7, 2, 98.736 );//  98.74

			int a;
			scanf ("%i", &a);//0x70;112; Read an optionally signed decimal, octal or hexadecimal integer. The corresponding argument is a pointer to an int.
			printf ("%d\n",  a );//112;112
			int b;
			scanf ("%x", &b);//0x70;70;112; Read a hexadecimal integer. The corresponding argument is a pointer to an unsigned int.
			printf ("%d\n",  b );//112;112;274
			
			double d;   double e;   double f;
			scanf ( "%le%lf%lg", &d, &e, &f );//1.27987 1.27987e+03 3.38476e-06; e, E, f, g or G Read a floating-point value. The corresponding argument is a pointer to a floating-point variable.
			printf( "%f %f %f ", d, e, f );//1.279870 1279.870000 0.000003
			float h;    float i;    float j;
			scanf ( "%e%f%g", &h, &i, &j );//1.27987 1.27987e+03 3.38476e-06; 
			printf( "%f %f %f ", h, i, j );//1.279870 1279.869995 0.000003

			char z[ 9 ];
			scanf ( "%8[aeiou]", z );//ooeeooahah; zooeeooahah; []A scan set is a set of characters enclosed in square brackets, [], and preceded by a percent sign in the format control string. 
			printf( "%s\n", z );//ooeeooa; ; If the first character in the input stream does not match a character in the scan set, the array is not modified.
			scanf ( "%8[^aeiou]", z );//String;aString
			printf( "%s\n", z);//Str; ; When a character contained in the inverted scan set is encountered, input terminates (Когда встречается символ, содержащийся в инвертированном наборе сканирования, ввод прекращается).

			int month;  int day;    int year;
			scanf ( "%d-%d-%d", &month, &day, &year );//11-22-33
			printf( "%d %d %d\n\n", month, day, year );//11 22 33
			scanf ( "%d%*c%d%*c%d", &month, &day, &year );//11/22/33; assignment suppression character *. This character enables scanf to read any type of data from the input and discard it without assigning it to a variable; CERT rule FIO00-C (www.securecoding.cert.org)
			printf( "%d %d %d\n\n", month, day, year );//11 22 33
			scanf ( "%d%*c%d%*c%d", &month, &day, &year );//11-22-33
			printf( "%d %d %d", month, day, year );//11 22 33
		}

Libs

	<ctype.h>
	int isspace( int c );// Returns a true value if c is a whitespace character—newline ('\n') 0x0A, space (' ') 0x20, form feed ('\f') 0x0C, carriage return ('\r') 0x0D, horizontal tab ('\t') or vertical tab ('\v')—and 0 otherwise.

	<stdlib.h>
	double strtod(/*from*/const char * nPtr,/*in*/char * * endPtr );// Converts the string nPtr to double.
	long strtol( const char * nPtr, char * * endPtr, int base );// Converts the string nPtr to long int.
	unsigned long strtoul( const char * nPtr, char * * endPtr, int base );// Converts the string nPtr to unsigned long int.

	void *malloc(size_t size);//function allocates the requested memory and returns a pointer to it; size − This is the size of the memory block, in bytes; This function returns a pointer to the allocated memory, or NULL if the request fails.
	void *calloc( size_t nmemb, size_t size );//calloc sets allocated memory to zero.
	void *realloc( void *ptr, size_t size );//
	void free( void* ptr );//

	example:
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int main () 
	{
	  char *str = NULL;
	  str = (char *) malloc(15); /* Initial memory allocation */
	  strcpy(str, "tutorialspoint");
	  printf("String = %s,  Address = %p\n", str, str);
	  str = (char *) realloc(str, 25);/* Reallocating memory */
	  strcat(str, ".com");
	  printf("String = %s,  Address = %p\n", str, str);
	  free(str);
	  return(0);
	}	
	//String = tutorialspoint,  Address = 00A41870
	//String = tutorialspoint.com,  Address = 00A41870

	<stdio.h>
	int sscanf(/*from*/char * s, const char * format, /*in*//*address*/ ... );// Equivalent to scanf, except the input is read from the array s rather than from the keyboard. Returns the number of items successfully read by the function, or EOF if an error occurs. 

	example:
	#include <stdio.h>
	int main ( void )
	{
		char M[10] = "1 2 3" ;
		int x, y;
		sscanf ( M, "%d%d", &x, &y );        
		printf ("%d %d", x,y);//1 2
	}

	int sprintf(/*in*/char * s,	const char * format, /*from*//*variables*/ ... );// The output is stored in the array s. The array pointed to by s is null terminated. Returns the number of characters written to s, or EOF if an error occurs. 

	example:
	#include <stdio.h>ц
	int main ( void )
	{
		int x = 2, y = 3;
		char M[10] = {0} ;
		sprintf( M, "x=%d y=%d", x, y ); 
		printf ("%s", M);//x=2 y=3
	}
		
	int snprintf(/*in*/char *rict buffer, size_t bufsz, const char *restrict format, ... );//Writes the results to a character string buffer. At most bufsz - 1 characters are written. The resulting character string will be terminated with a null character, unless bufsz is 0. 
	//bufsz должен учитывать терминатор.

	example:
	#include <stdio.h>
	int main ( void )
	{
		char var = 'A';
		char M[10] = {0} ;
		snprintf ( M, 2, "%c", var);//2=1+1 i.e. 'A' + '\0'
		printf("%s\n", M);//A
		printf("%d\n", snprintf( NULL, 0, "%d", -52 ) );//3 , if bufsz is 0, nothing is written and buffer may be a NULL pointer, however the return value (number of bytes that would be written not including the null terminator) is still calculated and returned. 
	}
	
FILE
	FILE *fopen(const char *fname, const char *mode);//
	Mode Description
		r Open an existing file for reading.
		w Create a file for writing. If the file already exists, discard the current contents.
		a Append: open or create a file for writing at the end of the file.
		r+ Open an existing file for update (reading and writing).
		w+ Create a file for update. If the file already exists, discard the current contents.
		a+ Append: open or create a file for update; writing is done at the end of the file.
		rb Open an existing file for reading in binary mode.
		wb Create a file for writing in binary mode. If the file already exists, discard the current contents.
		ab Append: open or create a file for writing at the end of the file in binary mode.
		rb+ Open an existing file for update (reading and writing) in binary mode.
		wb+ Create a file for update in binary mode. If the file already exists, discard thecurrent contents.
		ab+ Append: open or create a file for update in binary mode; writing is done at the end of the file.

	int fclose(FILE *stream);//

	int fscanf(/*from*/FILE *stream, const char *format, /*in*//*address*/ ... );// (until C99)  reads the data from file stream stream. 
	int scanf(/*from*//*stdin*/       const char *format, /*in*//*address*/ ... );​// (until C99)  reads the data from stdin и add '\0'
	//Function fscanf returns the number of data items successfully read or the value EOF if a problem occurs while reading data.
	int fprintf(/*in*/FILE *stream, const char *format,/*from*//*variables*/ ... );// (until C99) Loads the data from the given locations, converts them to character string equivalents and writes the results to the output stream stream. fprintf( stdout, "%s", "Ok" );
	int printf(/*in*//*stdout*/	const char *format, /*from*//*variables*/ ... );​// (until C99)

	example:
	#include <stdio.h>
	int main( void ) 
	{
		int n;
		char N[6];

		FILE *fPtr;//fPtr is a pointer to a FILE structure.
		fPtr = fopen( "clients.dat", "w");//Function fopen takes two arguments: a filename (which can include path information leading to the file’s location) and a file open mode. fopen returns a pointer to a FILE structure (defined in <stdio.h>) that contains information used to process the file. In some operating systems, this structure includes a file descriptor, i.e., an index into an operating system array called the open file table. Each array element contains a file control block (FCB)—information that the operating system uses to administer a particular file. Где эта структура? Кем создается? Или она уже есть? Как работают f-функции при повторном вызове?
		if ( fPtr == NULL ) 
		{
			puts( "File could not be opened" );
		}
		else 
		{	
			printf( "%s", "? " );
			scanf( "%d", &n );
			scanf( "%5s", &N[0] );//продолжит читать поток на следующей итерации...

			while( !( feof ( stdin ) ) )
			{//Line 24 uses function feof to determine whether the end-of-file indicator is set for the file to which stdin refers. The end-of-file indicator informs the program that there’s no more data to be processed. In Fig. 11.2, the end-of-file indicator is set for the standard input when the user enters the end-of-file key combination. The argument to function feof is a pointer to the file being tested for the end-of-file indicator (stdin in this case). The function returns a nonzero (true) value when the end-of-file indicator has been set; otherwise, the function returns zero.  

				fprintf( fPtr, "%d %s\n", n, &N[0] );//When the program issues an I/O call such as  fprintf( fPtr, "%d %s %.2f", n, name, balance ); the program locates the descriptor (7) in the FILE structure and uses the descriptor to find the FCB in the Open File Table.
				//Эта функция не запишет '\0' в конце массива. Символами newline LF (line ending, end of line, EOL) '\n' 0x0A и carriage return CR '\r' 0x0D будет завершена строка. Например, при вводе 1 и enter в файле появится 31 0d 0a.

				printf( "%s", "? " );
				scanf( "%d", &n );
				scanf( "%5s", &N[0] );

			}
			
			fclose( fPtr );
		} 


		fPtr = fopen ( "clients.dat", "r") ;
		if ( fPtr == NULL )
		{
			puts( "File could not be readed" );
		}
		else 
		{
			int request = 0;
			while ( request != 3 ) 
			{
				printf("%s", "request");
				scanf( "%u", &request );
				
				fscanf( fPtr, "%d %5s\n", &n, &N[0] );//Each time the second fscanf statement executes, the program reads another record from the file. fscanf must have before feof and switch. Читать нужно точно так же как записывалось.
				
				if ( request == 1 ) 
				{
					while ( !feof( fPtr ) ) 
					{
						if ( n > 0 ) 
						{
							printf( "%d %5s\n", n, &N[0] );
						} 
						fscanf( fPtr, "%d %5s\n", &n, &N[0] );
					}
				}
						
				if ( request == 2 )
				{
					while ( !feof( fPtr ) ) 
					{
						if ( n < 0 ) 
						{
							printf( "%d %5s\n", n, &N[0] );
						} 
						fscanf( fPtr, "%d %5s\n", &n, &N[0] );
					}
				}
									
				rewind( fPtr );//The statement causes a program’s file position pointer—which indicates the number of the next byte in the file to be read or written—to be repositioned to the beginning of the file (i.e., byte 0) pointed to by fPtr. The file position pointer is not really a pointer. Rather it’s an integer value that specifies the byte in the file at which the next read or write is to occur. This is sometimes referred to as the file offset. The file position pointer is a member of the FILE structure associated with each file.
			} 
			puts( "End of run." );
			fclose( fPtr ); 
		}
		return 0;
	}

Streams
	int fgetc  (/*from*/FILE *stream  );//Reads the next character from the given input stream. getc () may be implemented as a macro.
	int getchar(/*from*//*stdin*/ void);//Inputs the next character from the standard input and returns it as an integer. Equivalent to getc(stdin).

	int fputc  (/*from*/int ch, /*in*/ FILE *stream );//Function fputc, like putchar, writes one character to a file. Function fputc receives as arguments a character to be written and a pointer for the file to which the character will be written. The function call fputc( 'a', stdout ) writes the character 'a' to stdout—the standard output. This call is equivalent to putchar( 'a' ). putc () may be implemented as a macro
	int putchar(/*from*/ int c /*in*//*stdout*/ );//Prints the character stored in c and returns it as an integer.

	char *fgets(/*in*/ char *s, int n, /*from*/ FILE *stream  );// Inputs characters from the specified stream into the array s until a newline or end-of-file character is encountered, or until n - 1 bytes are read. A terminating null character is appended (добавляется в) to the array. Returns the string that was read into s. (until C99)
	char *gets (/*in*/ char *str     /*from*//*stdin*/ );//old.
	int fputs  (/*from*/ const consthar *str, /*in*/ FILE *stream );//(until C99) Writes every character from the null-terminated string str to the output stream stream, as if by repeatedly executing fputc. 
	int puts   (/*from*/ const char *s    /*in*//*stdout*/    );//Writes every character from the null-terminated string str and one additional newline character '\n' to the output stream stdout, as if by repeatedly executing fputc. Returns a nonzero integer if successful, or EOF if an error occurs.

	example:
	#include <stdio.h>
	#include <stdlib.h>
	void prnt (char * ptr, int count) ;
	int main( void ) 
	{
		char M [10] = {0};
		long value;

		fgets( &M[0], 5, stdin );//123456789; standard input stream sent to &M[0]. 4 байта + 1 байт '\0'. 
		prnt (&M[0], 10);//49 50 51 52 0 0 0 0 0 0
		value = strtol( &M[0], NULL, 0 );// strtol остановится на первом '\0'.
		printf ("%ld\n", value);//1234

		fgets( &M[0], 3, stdin );// продолжит читать поток после 1234...
		prnt (&M[0], 10);//53 54 0 52 0 0 0 0 0 0
		value = strtol( &M[0], NULL, 0 );
		printf ("%ld\n", value);//56

		fgets( &M[0], 5, stdin );
		prnt (&M[0], 10);//55 56 57 10 0 0 0 0 0 0
		
	}
	void prnt (char * ptr, int count) 
	{
		for (int i = 0; i != count; ++i) 
		{
			printf ("%d ", ptr[i] );
		}
		puts ("");
		return;
	}

	size_t fwrite(/*from*/ const void *buffer, size_t size, size_t count, /*in*/ FILE *stream );//(until C99); 
	// Writes count of objects from the given array buffer to the output stream stream. The objects are written as if by reinterpreting each object as an array of unsigned char and calling fputc size times for each object to write those unsigned chars into stream, in order (Объекты записываются, как если бы они интерпретировали каждый объект как массив беззнаковых символов и вызывали fputc size times для каждого объекта, чтобы записать эти беззнаковые символы в поток по порядку). The file position indicator for the stream is advanced by the number of characters written (Показатель увеличивается по количеству написанных символов).
	//fwrite( &mas[0], 4, 2, cfPtr ); запишет 2 раза по 4 байта int массива mas.
	//Function fwrite returns the number of items it successfully output. If this number is less than the third argument in the function call, then a write error occurred.
	size_t fread(/*in*/ void *buffer, size_t size, size_t count, /*from*/ FILE *stream );//(until C99); 
	//Function fread returns the number of items it successfully input. If this number is less than the third argument in the function call, then a read error occurred. 
	void rewind( FILE * stream );//The statement causes a program’s file position pointer—which indicates the number of the next byte in the file to be read or written—to be repositioned to the beginning of the file (i.e., byte 0) pointed to by cfPtr. The file position pointer is not really a pointer. Rather it’s an integer value that specifies the byte in the file at which the next read or write is to occur. This is sometimes referred to as the file offset. The file position pointer is a member of the FILE structure associated with each file.
	int fseek( FILE * stream, long offset, int origin );//Function fseek sets the file position pointer to a specific position in the file. Function fseek returns a nonzero value if the seek operation cannot be performed.Создание произвольного
	???
		#include <stdio.h>
		int main( void ) 
		{
			int a = 0xABCD;//in memory it is CD AB
			int b = 0x11223344;//65 0x41 0b 1000001

			FILE *cfPtr;
			cfPtr = fopen( "credit.dat", "wb" );

			fwrite( &a, 4, 1, cfPtr );
			fwrite( &b, 4, 1, cfPtr );
			
			fclose ( cfPtr );
			
			// cdab 0000 4433 2211 
			return 0;
		}

		#include <stdio.h>
		struct clientData 
		{
			unsigned int acctNum; //4
			char lastName[ 4 ];//4
			char firstName[ 4 ];//4
			int balance; //4
		}; 
		int main( void ) 
		{
			struct clientData blankClient = { 1, "ab", "b", 3 };

			FILE *cfPtr;
			cfPtr = fopen( "credit.dat", "wb" );
			if ( cfPtr  == NULL ) 
			{
				puts( "File could not be opened." );
			}
			else 
			{
			
				fwrite( &blankClient, sizeof( struct clientData ), 1, cfPtr );
				fwrite( &blankClient, sizeof( struct clientData ), 1, cfPtr );

				
				fclose ( cfPtr );
			}
			//0100 0000 6162 0000 6200 0000 0300 0000
			//0100 0000 6162 0000 6200 0000 0300 0000
			return 0;
		}

		#include <stdio.h>
		struct clientData {
			unsigned int acctNum; 
			char lastName[ 15 ];
			char firstName[ 10 ];
			double balance; 
		}; 
		int main( void ) {
			unsigned int i;
			struct clientData blankClient = { 0, "", "", 0.0 };

			FILE *cfPtr;
			cfPtr = fopen( "credit.dat", "wb" );

			if ( cfPtr  == NULL ) {
				puts( "File could not be opened." );
			}
			else {
			
				for ( i = 1; i <= 100; ++i ) 
				{
					fwrite( &blankClient, sizeof( struct clientData ), 1, cfPtr );
				}

				fclose ( cfPtr );
			}
			return 0;
		}

Запись произвольного в режиме обновления
	???	
		#include <stdio.h>
		struct clientData {
			unsigned int acctNum;
			char lastName[ 15 ];
			char firstName[ 10 ];
			double balance;
		};
		int main( void ){
			FILE *cfPtr;
			cfPtr = fopen( "credit.dat", "rb+" );//rb+ не создает файл
			struct clientData client = { 0, "", "", 0.0 };  
			if ( cfPtr  == NULL ) {
				puts( "File could not be opened." );
			}
			else {
				printf( "%s", "Enter account number"
						" ( 1 to 100, 0 to end input )\n? " );
				scanf( "%d", &client.acctNum );
				while ( client.acctNum != 0 ) {
					printf( "%s", "Enter lastname, firstname, balance\n? " );
					fscanf( stdin, "%14s%9s%lf", client.lastName, client.firstName, &client.balance );

					fseek( cfPtr, ( client.acctNum - 1 ) * sizeof( struct clientData ), SEEK_SET );//Lines 40–41 position the file position pointer for the file referenced by cfPtr to the byte location calculated by (client.accountNum - 1) * sizeof(struct clientData). The value of this expression is called the offset or the displacement. 
					//Because the account number is between 1 and 100 but the byte positions in the file start with 0, 1 is subtracted from the account number when calculating the byte location of the record. Thus, for record 1, the file position pointer is set to byte 0 of the file. 
					//The symbolic constant SEEK_SET indicates that the file position pointer is positioned relative to the beginning of the file by the amount of the offset. 
					//SEEK_SET indicates that the seek starts at the beginning of the file; SEEK_CUR indicates that the seek starts at the current location in the file; and SEEK_END indicates that the seek starts at the end of the file. 
					//Function fseek returns a nonzero value if the seek operation cannot be performed.
					
					fwrite( &client, sizeof( struct clientData ), 1, cfPtr );
					//For simplicity, the programs in this chapter do not perform error checking (fscanf, fseek, fwrite). 

					printf( "%s", "Enter account number\n? " );
					scanf( "%d", &client.acctNum );
				}
				fclose( cfPtr );
			}
			return 0;
		}

Чтение произвольного
	???
		#include <stdio.h>
		struct clientData {
			unsigned int acctNum;
			char lastName[ 15 ];
			char firstName[ 10 ];
			double balance;
		};
		int main( void ){
			FILE *cfPtr;
			int errorControl;
			//struct clientData client = { 0, "", "", 0.0 };
			struct clientData client;
			if ( ( cfPtr = fopen( "credit.dat", "rb" ) ) == NULL ) {
				puts( "File could not be opened." );
			} 
			else {
				printf( "%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance" );
				while ( !feof( cfPtr ) ) {
					errorControl = fread( &client, sizeof( struct clientData ), 1, cfPtr );
					if ( errorControl != 0 && client.acctNum != 0 ) {// проверка на ошибку и запрет на вывод мемберов с acctNum = 0, то есть не измененными после создания.
						printf( "%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance );
					}
				}
			fclose( cfPtr );
			}
			return 0;
		}

STRINGS
	???
		<string.h>
		char * strcpy( char * s1, const char * s2 )// Copies string s2 into array s1. The value of s1 is returned.
		char * strncpy( char * s1, const char * s2, size_t n )// Copies at most n characters of string s2 into array s1. The value of s1 is returned
		char * strcat( char * s1, const char * s2 )// Appends string s2 to array s1. The first character of s2 overwrites the terminating null character of s1. The value of s1 is returned.
		char * strncat( char * s1, const char * s2, size_t n )// Appends at most n characters of string s2 to array s1. The first character of s2 overwrites the terminating null character of s1. The value of s1 is returned.
		int strcmp( const char *s1, const char *s2 );// Compares the string s1 with the string s2. The function returns 0, less than 0 or greater than 0 if s1 is equal to, less than or greater than s2, respectively.
		int strncmp( const char *s1, const char *s2, size_t n );// Compares up to n characters of the string s1 with the string s2. The function returns 0, less than 0 or greater than 0 if s1 is equal to, less than or greater than s2, respectively. 
		char * strchr( const char * s, int c );// Locates the first occurrence (вхождение) of character c in string s. If c is found, a pointer to c in s is returned. Otherwise, a NULL pointer is returned. 
		char * strstr( const char * s1, const char * s2 );// Locates the first occurrence in string s1 of string s2. If the string is found, a pointer to the string in s1 is returned. Otherwise, a NULL pointer is returned. 
		char * strtok( char * s1, const char * s2 );// A sequence of calls (последовательность вызовов функции) to strtok breaks string s1 into tokens (лексемы) —logical pieces such as words in a line of text—separated by characters contained in string s2. Причем, '\0' строки s2 неинтересен. The first call contains s1 as the first argument, and subsequent calls to continue tokenizing the same string contain NULL as the first argument. A pointer to the current token is returned by each call. If there are no more tokens when the function is called, NULL is returned.

		void * memcpy( void * s1, const void * s2, size_t n );//Copies n characters from the object pointed to by s2 into the object pointed to by s1. A pointer to the resulting object is returned.
		void * memmove( void * s1, const void * s2, size_t n );//Copies n characters from the object pointed to by s2 into the object pointed to by s1. The copy is performed as if the characters were first copied from the object pointed to by s2 into a temporary array and then from the temporary array into the object pointed to by s1. A pointer to the resulting object is returned.
		int memcmp( const void * s1, const void * s2, size_t n );//Compares the first n characters of the objects pointed to by s1 and s2. The function returns 0, less than 0 or greater than 0 if s1 is equal to, less than or greater than s2.
		void * memchr( const void * s, int c, size_t n );//Locates the first occurrence of c (converted to unsigned char) in the first n characters of the object pointed to by s. If c is found, a pointer to c in the object is returned. Otherwise, NULL is returned.
		void * memset( void * s, int c, size_t n );//Copies c (converted to unsigned char) into the first n characters of the object pointed to by s. A pointer to the result is returned.

		size_t strlen( const char * s );// Determines the length of string s. The number of characters preceding the terminating null character is returned.    
		example:
		#include <stdio.h>
		#include <string.h>
		void prnt (char * Ptr, int count);
		int main( void ) {
			char A [] = "zzzzzzzzzz";
			char B [] = "abcd";
			prnt (A, sizeof(A) );//zzzzzzzzzz
			strncpy (A, B, 4 );
			prnt (A, sizeof(A) );//abcdzzzzzz
			strncpy (A, B, 5 );
			prnt (A, sizeof(A) );//abcd zzzzz
			strncpy (A, B, 6 );
			prnt (A, sizeof(A) );//abcd  zzzz

			char C [] = "aaazbbbzccczdddzeeezfff";
			char * tokenPtr;
			tokenPtr = strtok( C, "z" );// первый вызов strtok, будет найдена первая лексема.
			while ( tokenPtr != NULL ) {// возвратит NULL, когда лексемы закончатся.
				printf( "%s ", tokenPtr );// в цикле aaa bbb ccc ddd eee fff
				tokenPtr = strtok( NULL, "z" );// искать следующую встречу z
			}
			puts ("");

			char s1 [17];
			char s2 [] = "Copy this string"; 
			memcpy( s1, s2, 17 );
			printf( "%s\n", s1 );//Copy this string
			int M1 [3] = {0};
			int M2 [] = {4,5,6};        
			for (int i = 0; i != 12; ++i ) {
				printf ("%d ", i );
				memcpy( M1, M2, i );
				for (int i = 0; i != 3; ++i ) {
					printf ("%d", M1[i] );
				}
				puts ("");
			}
			//0 000
			//1 400
			//2 400
			//3 400
			//4 400
			//5 450
			//6 450
			//7 450
			//8 450
			//9 456
			//10 456
			//11 456

			int Y [] = {1,2,3,4,9,6};
			int Z [] = {1,2,3,5,4,3};
			printf( "%d\n", memcmp(Y,Z,12) );//0
			printf( "%d\n", memcmp(Y,Z,13) );//-1 важно первое "больше/меньше"
			printf( "%d\n", memcmp(Y,Z,24) );//-1

			int a;
			memset(&a, 65, 4);//65 = 0b01000001
			printf ("%d", a);//1094795585 или 0100 0001  0100 0001  0100 0001  0100 0001
			int n[ 10 ];//
			//memset(n, 0, 10);//we could have initialized the 10-element array n with memset(n, 0, 10); нет.
			memset(n, 0, 10*4 );// да.
		}
		void prnt (char * Ptr, int count ) {
			for (int i = 0; i != count; ++i ) {
				printf ("%c", Ptr[i] );
			}
			puts ("");
			return;
		}

	Reading Numeric Inputs and Input Validation
	It’s important to validate the data that you input into a program. For example, when you ask the user to enter an integer in the range 1–100 then attempt to read that integer using scanf, there are several possible problems. The user could enter an integer that’s outside the program’s required range, an integer that’s outside the allowed range for integers on that computer, a non-integer numeric value or a non-numeric value. You can use various functions that you learned in this chapter to fully validate such input. For example, you could
			• use fgets to read the input as a line of text
			• convert the string to a number using strtol and ensure that the conversion was successful, then
			• ensure that the value is in range.
		For more information and techniques for converting input to numeric values, see CERT guideline INT05-C at www.securecoding.cert.org.

A linked list
	A linked list is a linear collection of self-referential structures, called nodes, connected by pointer links—hence, the term “linked” list. A linked list is accessed via a pointer to the first node of the list. Subsequent nodes are accessed via the link pointer member stored in each node. By convention, the link pointer in the last node of a list is set to NULL to mark the end of the list. 
	Fig. 12.3: fig12_03.c
		#include <stdio.h>
		#include <stdlib.h>
		struct listNode 
		{
			char data;
			struct listNode * nextPtr;
		};
		// typedef struct listNode ListNode;
		// typedef ListNode * ListNodePtr;

		void insert( struct listNode **sPtr, char value );
		char delete( struct listNode **sPtr, char value );
		int isEmpty( struct listNode *sPtr );
		void printList( struct listNode *currentPtr );
		void instructions( void );

		int main( void )
		{
			struct listNode *startPtr = NULL;
			unsigned int choice = 0; 
			char item; 
			while ( choice != 3 ) 
			{
				instructions(); 
				printf( "%s", "? " ); 
				scanf ( "%u", &choice );

				if (choice == 1)
				{
					printf( "%s", "Enter a character to be inserted: " );
					scanf( "\n%c", &item );
					insert( &startPtr, item );
					printList( startPtr );
				}		
				if (choice == 2 )
				{
					if ( !isEmpty( startPtr ) ) 
					{
						printf( "%s", "Enter character to be deleted: " );
						scanf( "\n%c", &item );
						if ( delete( &startPtr, item ) )
						{
							printf( "%c deleted.\n", item );
							printList( startPtr );
						}
						else 
						{
							printf( "%c not found.\n\n", item );
						}
					}
					else 
					{
						puts( "List is empty.\n" );
					}
				}
			}
			puts( "End of run." );
		}
		void instructions( void ) {
			puts( "Enter your choice:\n"
			" 1 to insert an element into the list.\n"
			" 2 to delete an element from the list.\n"
			" 3 to end." );
			return;
		}
		void insert( struct listNode * * sPtr, char value ) 
		{
			struct listNode * newPtr;
			struct listNode * previousPtr;
			struct listNode * currentPtr;
			newPtr = malloc( sizeof( struct listNode ) );
			if ( newPtr != NULL ) 
			{ 
				//На самом деле для понимания нужно было просто написать список, в который просто последовательно вставляются любые данные, после чего вывести список на экран. А не пытаться сразу раскурить список с возможностью вставки ноды в начало или в середину.
				// Примитивная задача вставить в начало или в конец списка - примитивное костыльное решение. Необходимо предусмотреть нулевой каррент проверкой, потому что доступ к линку нулевого указателя приведет к беде. Затем задача усложняется вставкой перед нодой. Тогда решение эволюционирует так далеко, что исчезает акт доступа к линку, а за ним и проверка нулевого карента. 
				// if ( current_node_ptr == NULL )
				// {
				// 	*list_ptr_changer = new_node_ptr ; 
				// }
				// else 
				// {
				// 	while ( current_node_ptr -> link != NULL )
				// 	{
				// 		intersection ( &(current_node_ptr -> data)  
				// 		current_node_ptr = current_node_ptr -> link ;
				// 	}
				// 	current_node_ptr -> link = new_node_ptr ;

				newPtr->data = value;
				newPtr->nextPtr = NULL;
				
				currentPtr = *sPtr;// Разыменовали чэйнжер, фактически получили внутри функции точно такой же списочный указатель, как и в вызывающей функции. Чэйнжер остается для доступа в исходное начало, карент для прицеливания.
				previousPtr = NULL;// Карент является как бы основным указателем, основым прицелом, а привиоус как бы вспомогательным, позволяя не терять предыдущую ноду. Каррент используется в условии, прыгая по линкам, а привиоус как способ доступа к предыдущей ноде. Если новый элемент нужно вставить перед каррентом, то нулевой привиоус позволит обнаружить начало списка, а значит не только вставить перед каррентом, но и изменить чэйнжер. Не нулевой превиос поможет при вставке в середину (то есть между двумя нодами), и при вставке в самое начало (то есть перед нодой).

				//Движение.
				while 
				( 
					currentPtr != NULL && // список не пуст
					currentPtr != NULL && // список не закончился
					value > currentPtr->data ) // остается необходимость движения
				//while ( !( currentPtr == NULL || value < currentPtr->data ) ) // Или не(условие, когда нужно остановиться - когда список пустой (то есть закончился не успев начаться), когда список закончился (то есть currnetPtr вышел за пределы списка) или когда новые данные будут меньше следующих). 
				{
					previousPtr = currentPtr ;
					currentPtr = currentPtr->nextPtr ;
				}

				// Вставка в начало.
				if ( previousPtr == NULL ) //либо список пуст, либо не пуст, но произошла остановка на первом элементе. 
				// Если currentPtr == NULL, то список пустой (то есть закончился не успев начаться) или список закончился (то есть currnetPtr вышел за пределы списка). Тогда в первом случае previousPtr == NULL, а во втором случае равен предыдущей ноде. Тогда это условие сработает в первом случае и поможет изменить линк новой ноды и перезаписать списочный указатель sPtr. 
				// Если currentPtr != NULL, то список не пуст, но если вместе с этим previousPtr == NULL, то currnetPtr указывает на первый элемент. Это значит, что цикл остановился в самом начале, потому что вставляемое число меньше, чем в первом элементе списка. Тогда это условие снова поможет изменить линк новой ноды и перезаписать списочный указатель sPtr. 
				// При вставке в середину (то есть между двумя нодами) или в самый конец (то есть после ноды) previousPtr != NULL, поэтому нужно отдельное условие.
				{
					// newPtr->nextPtr = currentPtr ;
					newPtr->nextPtr = *sPtr ;
					*sPtr = newPtr ;
				}

				//Вставка в середину или в конец.
				else //if ( previousPtr != NULL ), то список не нулевой, а мы дошли либо до середины, либо до конца. Тогда через previousPtr у предыдущей ноды меняется линк на новый узел. А в линк newPtr закатывается адрес текущей ноды с помощью currentPtr. Если дело происходит в середине - то currentPtr указывает на узел, если в конце - то на нулл.
				{
					previousPtr->nextPtr = newPtr;
					newPtr->nextPtr = currentPtr;
				}
				//хэпиэнд

			}
			else {
				printf( "%c not inserted. No memory available.\n", value );
			}
			return;
		}
		char delete( struct listNode * *sPtr, char value ){
			struct listNode * previousPtr;
			struct listNode * currentPtr;
			struct listNode * tempPtr;
			if ( value == ( *sPtr )->data ) {
				tempPtr = *sPtr;
				*sPtr = ( *sPtr )->nextPtr;
				free( tempPtr );
				return value;
			}
			else {
				previousPtr = *sPtr;
				currentPtr = ( *sPtr )->nextPtr;
				while ( currentPtr != NULL && currentPtr->data != value ) {
					previousPtr = currentPtr;
					currentPtr = currentPtr->nextPtr;
				}
				if ( currentPtr != NULL ) {
					tempPtr = currentPtr;
					previousPtr->nextPtr = currentPtr->nextPtr;
					free( tempPtr );
					return value;
				}
			}
			return '\0';
		}
		int isEmpty( struct listNode * sPtr ){

			return sPtr == NULL;
		}
		void printList( struct listNode * currentPtr ){
			if ( isEmpty( currentPtr ) ) {

				puts( "List is empty.\n" );
			}
			else {
				puts( "The list is:" );
				while ( currentPtr != NULL ) {
					printf( "%c --> ", currentPtr->data );
					currentPtr = currentPtr->nextPtr;
				}
				puts( "NULL\n" );
			} 
		}
