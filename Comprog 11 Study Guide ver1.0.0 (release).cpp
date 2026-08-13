#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Windows API for Sleep(), Beep(), and Console Encoding

// Color definitions
#define COLOR_RESET  "\033[0m"
#define COLOR_HEADER "\033[1;36m" // Cyan
#define COLOR_TITLE  "\033[1;33m" // Yellow
#define COLOR_TERM   "\033[1;32m" // Green
#define COLOR_CODE   "\033[0;35m" // Purple
#define COLOR_RED    "\033[1;31m" // Red

// Global Flag to unlock Finale Mode after completing option 5 with >= 80% score
int hasCompletedAllTopics = 0;

// Fast typewriter animation function with typing audio feedback
void typeWriter(const char* text, int msDelay) {
    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout);
        
        // Play subtle keyclick tone for visible characters
        if (text[i] != ' ' && text[i] != '\n') {
            Beep(800, 5); // Pitch: 800Hz, Duration: 5ms
        }
        
        Sleep(msDelay);
    }
}

// Sound Feedback System for Answers
void playSound(int isCorrect) {
    if (isCorrect) {
        Beep(523, 100); // C5
        Beep(659, 150); // E5
    } else {
        Beep(200, 250); // Low error buzzer
    }
}

void clearBuffer(void) {
    while (getchar() != '\n');
}

// Interactive Exercise: Fill-in-the-Blank Code Practice (Returns 1 for correct, 0 for incorrect)
int fillInTheBlank(const char* promptText, const char* expectedAnswer, const char* hintText, const char* simpleExplanation, const char* easyTip) {
    char userInput[50];
    int isCorrect = 0;
    printf("\n");
    typeWriter("[CODE PRACTICE]\n", 10);
    printf("%s\n", promptText);
    printf("%sHINT:%s %s\n", COLOR_TITLE, COLOR_RESET, hintText);
    typeWriter("Type your answer: ", 10);
    
    if (scanf("%49s", userInput) == 1) {
        if (strcmp(userInput, expectedAnswer) == 0) {
            playSound(1);
            printf("%s[✓] Correct!%s Nice job!\n\n", COLOR_TERM, COLOR_RESET);
            isCorrect = 1;
        } else {
            playSound(0);
            printf("%s[X] Oops! You typed: '%s'%s\n", COLOR_RED, userInput, COLOR_RESET);
            printf("--------------------------------------------------\n");
            printf("%s• Right Answer:%s %s\n", COLOR_TITLE, COLOR_RESET, expectedAnswer);
            printf("%s• Detailed Explanation:%s\n  %s\n", COLOR_RED, COLOR_RESET, simpleExplanation);
            printf("%s• Pro Tip for Next Time:%s\n  %s\n", COLOR_TERM, COLOR_RESET, easyTip);
            printf("--------------------------------------------------\n\n");
        }
    }
    clearBuffer();
    return isCorrect;
}

// Interactive Exercise: Output Challenge (Returns 1 for correct, 0 for incorrect)
int outputChallenge(const char* targetOutput, const char* correctCodeSnippet, const char* expectedKeyword, const char* hintText, const char* simpleExplanation, const char* easyTip) {
    char userInput[100];
    int isCorrect = 0;
    printf("%s[OUTPUT MATCH CHALLENGE]%s\n", COLOR_HEADER, COLOR_RESET);
    printf("TARGET OUTPUT:\n----------------\n%s----------------\n", targetOutput);
    printf("%sHINT:%s %s\n", COLOR_TITLE, COLOR_RESET, hintText);
    typeWriter("Type the C keyword needed:\n> ", 10);
    
    if (scanf("%99s", userInput) == 1) {
        if (strstr(userInput, expectedKeyword) != NULL) {
            playSound(1);
            printf("%s[✓] You got it!%s Code used:\n%s%s%s\n\n", COLOR_TERM, COLOR_RESET, COLOR_CODE, correctCodeSnippet, COLOR_RESET);
            isCorrect = 1;
        } else {
            playSound(0);
            printf("%s[X] Not quite! You typed: '%s'%s\n", COLOR_RED, userInput, COLOR_RESET);
            printf("--------------------------------------------------\n");
            printf("%s• Needed Word:%s '%s'\n", COLOR_TITLE, COLOR_RESET, expectedKeyword);
            printf("%s• Detailed Explanation:%s\n  %s\n", COLOR_RED, COLOR_RESET, simpleExplanation);
            printf("%s• Pro Tip for Next Time:%s\n  %s\n", COLOR_TERM, COLOR_RESET, easyTip);
            printf("%s• Example Code Solution:%s\n%s%s%s\n", COLOR_TITLE, COLOR_RESET, COLOR_CODE, correctCodeSnippet, COLOR_RESET);
            printf("--------------------------------------------------\n\n");
        }
    }
    clearBuffer();
    return isCorrect;
}

void showPrelim(void) {
    system("cls");
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
    typeWriter("                 PRELIM TOPICS                    \n", 5);
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
    
    printf("\n1. %sPROBLEM SOLVING PROCESS%s\n", COLOR_TITLE, COLOR_RESET);
    typeWriter("   * Every computer program solves a problem by taking raw input, performing calculations, and displaying output.\n", 8);
    printf("   * %sKey Breakdown:%s Input (data given) -> Processing (doing work/math) -> Output (showing the result).\n", COLOR_TERM, COLOR_RESET);

    printf("\n2. %sFLOWCHARTING & PSEUDOCODE%s\n", COLOR_TITLE, COLOR_RESET);
    typeWriter("   * Before typing code, programmers map out logic using diagrams (flowcharts) or plain English (pseudocode).\n", 8);
    printf("   * %sStandard Shapes:%s Oval (Start/End), Parallelogram (Input/Output), Rectangle (Action/Process), Diamond (Decision).\n", COLOR_TERM, COLOR_RESET);

    printf("\n3. %sBASIC C STRUCTURE%s\n", COLOR_TITLE, COLOR_RESET);
    typeWriter("   * C programs start execution inside main(). Header files like <stdio.h> provide functions for input and output.\n\n", 8);

    printf("%s--- LESSON CODE EXAMPLE ---%s\n", COLOR_CODE, COLOR_RESET);
    printf("#include <stdio.h>\n\n");
    printf("%sint%s main(void) {\n", COLOR_TERM, COLOR_RESET);
    printf("    %sprintf%s(\"Hello World!\");\n", COLOR_TERM, COLOR_RESET);
    printf("    return 0;\n");
    printf("}\n");
    printf("%s---------------------------%s\n\n", COLOR_CODE, COLOR_RESET);

    fillInTheBlank(
        "___ main(void) { return 0; } // What data type word goes before main?", 
        "int",
        "It starts with 'i' and stands for 'integer' (whole number).",
        "The computer expects main() to return a status code upon finishing. Returning 0 signals success to the OS. Because 0 is a whole number, we must declare the return type as 'int'.",
        "When a function ends with 'return 0;', its return type at the top must be 'int'."
    );

    outputChallenge(
        "Hello World", 
        "printf(\"Hello World\");", 
        "printf",
        "Type the C function used to print text on screen (starts with 'p').",
        "C uses 'printf' (print formatted) from <stdio.h> to output text to the console screen.",
        "C is strict about function names. Plain 'print' or 'cout' will throw compiler errors."
    );

    fillInTheBlank(
        "#include <___> // Which header file is required for printf() and scanf()?", 
        "stdio.h",
        "Stands for 'Standard Input Output'. Ends with '.h'.",
        "<stdio.h> contains essential declarations for input/output operations like reading user input and printing to screen.",
        "Always include <stdio.h> at the top of your program whenever you need console printing or keyboard input."
    );
}

void showMidterm(void) {
    system("cls");
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
    typeWriter("                 MIDTERM TOPICS                   \n", 5);
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);

    printf("\n1. %sSEQUENTIAL STRUCTURES%s\n", COLOR_TITLE, COLOR_RESET);
    typeWriter("   * Statements execute line-by-line from top to bottom in strict consecutive order.\n", 8);

    printf("\n2. %sSELECTION STRUCTURES (DECISIONS)%s\n", COLOR_TITLE, COLOR_RESET);
    typeWriter("   * Code branches down different paths based on whether conditions evaluate to true or false.\n", 8);
    printf("   * %sKey Keywords:%s if, else if, else, switch, case, break.\n", COLOR_TERM, COLOR_RESET);

    printf("\n3. %sREPETITION STRUCTURES (LOOPS)%s\n", COLOR_TITLE, COLOR_RESET);
    typeWriter("   * Code repeats a block of statements continuously until a stopping condition is satisfied.\n", 8);
    printf("   * %sKey Keywords:%s for, while, do-while.\n\n", COLOR_TERM, COLOR_RESET);

    printf("%s--- LESSON CODE EXAMPLE ---%s\n", COLOR_CODE, COLOR_RESET);
    printf("// Decision Example\n");
    printf("%sif%s (score >= 75) {\n    printf(\"Passed!\");\n} %selse%s {\n    printf(\"Failed!\");\n}\n\n", COLOR_TERM, COLOR_RESET, COLOR_TERM, COLOR_RESET);
    printf("// Loop Example (Counts 1 to 3)\n");
    printf("%sfor%s (int i = 1; i <= 3; i++) {\n    printf(\"%%d\\n\", i);\n}\n", COLOR_TERM, COLOR_RESET);
    printf("%s---------------------------%s\n\n", COLOR_CODE, COLOR_RESET);

    fillInTheBlank(
        "___ (int i = 0; i < 5; i++) { ... } // What keyword creates a counting loop?", 
        "for",
        "It's a 3-letter word starting with 'f'.",
        "The 'for' loop handles counter-controlled repetition by combining initialization, condition checking, and counter increments into one line.",
        "When you know the exact number of iterations needed in advance, use a 'for' loop."
    );

    fillInTheBlank(
        "if (age >= 18) { ... } ___ { printf(\"Minor\"); } // What keyword handles the alternative branch?", 
        "else",
        "Starts with 'e' and pairs with 'if'.",
        "The 'else' keyword defines a fallback block of code that executes only when the preceding 'if' condition evaluates to false.",
        "Use 'if' for the primary condition and 'else' for everything that doesn't meet that condition."
    );

    outputChallenge(
        "1\n2\n3\n", 
        "for(int i = 1; i <= 3; i++) {\n    printf(\"%d\\n\", i);\n}", 
        "for",
        "Which loop keyword handles running code multiple times in a row?",
        "Wrapping a single printf call inside a 'for' loop lets you output sequential patterns without duplicating print statements.",
        "Whenever target output shows sequential numbers (1, 2, 3...), use a 'for' loop."
    );
}

void showSemiFinals(void) {
    system("cls");
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
    typeWriter("               SEMI FINALS TOPICS                 \n", 5);
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);

    printf("\n1. %sFUNCTIONS & SCOPE%s\n", COLOR_TITLE, COLOR_RESET);
    typeWriter("   * Functions are modular blocks of code designed to perform specific tasks, preventing duplicate code.\n", 8);
    printf("   * %sCore Concepts:%s Inputs (parameters) pass data into functions; return values send results back.\n\n", COLOR_TERM, COLOR_RESET);

    printf("%s--- LESSON CODE EXAMPLE ---%s\n", COLOR_CODE, COLOR_RESET);
    printf("// Returns an integer result\n");
    printf("int add(int a, int b) {\n    %sreturn%s a + b;\n}\n\n");
    printf("// Returns NOTHING (action-only)\n");
    printf("%svoid%s sayHi(void) {\n    printf(\"Hi!\");\n}\n", COLOR_TERM, COLOR_RESET);
    printf("%s---------------------------%s\n\n", COLOR_CODE, COLOR_RESET);

    fillInTheBlank(
        "int add(int a, int b) { ___ a + b; } // Type the word that hands the calculation back.", 
        "return",
        "Starts with 'r' and ends with 'n'.",
        "The 'return' keyword passes calculated data out of a function back to the calling code and immediately stops function execution.",
        "Functions declared with a non-void data type (like int or float) must contain a 'return' statement."
    );

    fillInTheBlank(
        "___ displayMenu(void) { printf(\"1. Start\\n2. Exit\"); } // Function returns no value.", 
        "void",
        "A 4-letter word starting with 'v' meaning 'empty'.",
        "When a function performs an action (like printing) without calculating a result to hand back, its return type is defined as 'void'.",
        "If your function has no return value, write 'void' before its name."
    );

    outputChallenge(
        "Score: 100", 
        "void printScore(int s) {\n    printf(\"Score: %d\", s);\n}", 
        "void",
        "What return type keyword is used for functions that print output without returning data?",
        "Functions designed purely for console output use 'void' to explicitly declare that no return value is being calculated.",
        "If a function contains print statements but no 'return' statement, set its return type to 'void'."
    );
}

void showFinals(void) {
    system("cls");
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
    typeWriter("                 FINALS TOPICS                    \n", 5);
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);

    printf("\n1. %sARRAYS & TRAVERSAL%s\n", COLOR_TITLE, COLOR_RESET);
    typeWriter("   * An array stores multiple elements of the same data type sequentially in memory.\n", 8);
    printf("   * %sZero-Indexing Rule:%s Array index positions always start counting at 0, not 1!\n\n", COLOR_TERM, COLOR_RESET);

    printf("%s--- LESSON CODE EXAMPLE ---%s\n", COLOR_CODE, COLOR_RESET);
    printf("// Declare an array of 3 numbers\n");
    printf("int numbers[3] = {10, 20, 30};\n\n");
    printf("// Position Breakdown:\n");
    printf("// numbers[0] -> 10 (1st item)\n");
    printf("// numbers[1] -> 20 (2nd item)\n");
    printf("// numbers[2] -> 30 (3rd item)\n");
    printf("%s---------------------------%s\n\n", COLOR_CODE, COLOR_RESET);

    fillInTheBlank(
        "int numbers[3] = {10, 20, 30};\nprintf(\"%d\", numbers[___]); // What index number gets the FIRST item (10)?", 
        "0",
        "C array indexing starts at zero.",
        "Memory positions in C start at index offset [0]. The first element is always at index [0], second at [1], third at [2].",
        "Always subtract 1 from the item position number to find its index (Item 1 = index [0])."
    );

    fillInTheBlank(
        "int marks[4] = {80, 85, 90, 95};\nprintf(\"%d\", marks[___]); // What index accesses the LAST item (95)?", 
        "3",
        "An array of size 4 has index range [0] to [size - 1].",
        "Because array indices start at 0, an array of size N has valid indices from 0 to N-1. For size 4, the last element is at index [3].",
        "The last element of an array with N items is always at index [N - 1]."
    );

    outputChallenge(
        "Item: A", 
        "char list[1] = {'A'};\nprintf(\"Item: %c\", list[0]);", 
        "list",
        "Type the variable name of the array shown in the code above.",
        "Accessing array elements requires using the declared array identifier followed by square brackets enclosing the target index.",
        "Always match the exact array name used in your declaration when referencing elements."
    );
}

// Option 5: Comprehensive Practice (Exam Mode with Score Evaluation)
void showComprehensivePractice(void) {
    int score = 0;
    int totalQuestions = 6;

    system("cls");
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
    typeWriter("       COMPREHENSIVE PRACTICE (EXAM MODE)         \n", 5);
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
    printf("Testing all curriculum topics with fresh practice challenges.\n");
    printf("Passing Score: 80%% (at least 5/6 correct) to unlock Finale Sandbox.\n\n");

    // Fresh Prelim Practice
    printf("%s--- SECTION 1: PRELIM REVISION ---%s\n", COLOR_TITLE, COLOR_RESET);
    score += fillInTheBlank(
        "___ x = 15; // Which primitive C data type keyword stores whole numbers?", 
        "int",
        "Starts with 'i' and holds non-decimal integers.",
        "The 'int' data type is used in C to store whole numbers like 15, -5, or 0 without decimals.",
        "Use 'int' for whole counts, and 'float' or 'double' when working with decimal places."
    );

    score += outputChallenge(
        "System Ready", 
        "printf(\"System Ready\");", 
        "printf",
        "Name the primary library function used to print text output to console.",
        "The printf function formats and sends output to stdout.",
        "Ensure <stdio.h> is included at the top of your program whenever calling printf."
    );

    // Fresh Midterm Practice
    printf("%s--- SECTION 2: MIDTERM REVISION ---%s\n", COLOR_TITLE, COLOR_RESET);
    score += fillInTheBlank(
        "while (count < 5) { count++; } // Which word creates a condition-driven loop?", 
        "while",
        "Starts with 'w' and checks conditions before running.",
        "A 'while' loop checks its expression first, repeating code as long as the condition evaluates to true.",
        "Use 'while' loops when you don't know the exact number of iterations beforehand."
    );

    score += fillInTheBlank(
        "switch (choice) { ___ 1: printf(\"One\"); break; } // Keyword for matching switch branches?", 
        "case",
        "Starts with 'c' and handles individual value branches in a switch.",
        "The 'case' keyword specifies a label to jump to when a switch expression matches its value.",
        "Always follow each case block with a 'break' statement to prevent fallthrough."
    );

    // Fresh Semi-Finals Practice
    printf("%s--- SECTION 3: SEMI-FINALS REVISION ---%s\n", COLOR_TITLE, COLOR_RESET);
    score += fillInTheBlank(
        "int square(int val) { ___ val * val; } // Keyword that yields the squared value.", 
        "return",
        "Sends the calculated result back to caller.",
        "The 'return' statement terminates execution of a function and passes the computed expression back.",
        "Non-void functions must execute a return statement that yields a matching data type."
    );

    // Fresh Finals Practice
    printf("%s--- SECTION 4: FINALS REVISION ---%s\n", COLOR_TITLE, COLOR_RESET);
    score += fillInTheBlank(
        "float rates[5]; // Access the 3rd element: rates[___];", 
        "2",
        "Remember: 1st is [0], 2nd is [1], 3rd is [2].",
        "With 0-based indexing, element index N corresponds to position N+1. Therefore, index 2 accesses the 3rd element.",
        "To target item position P, use index offset [P - 1]."
    );

    // Score Evaluation Logic
    double percentage = ((double)score / totalQuestions) * 100.0;
    
    printf("==================================================\n");
    printf("%sEXAM RESULTS%s\n", COLOR_HEADER, COLOR_RESET);
    printf("Score: %d / %d (%.1f%%)\n", score, totalQuestions, percentage);
    printf("--------------------------------------------------\n");

    if (percentage >= 80.0) {
        hasCompletedAllTopics = 1; // Unlock Finale Sandbox
        playSound(1);
        printf("%s[✓] CONGRATULATIONS! You passed with %.1f%% and unlocked the Finale Sandbox!%s\n", COLOR_TERM, COLOR_RESET, percentage);
    } else {
        playSound(0);
        printf("%s[X] FAILED (Below 80%% passing threshold)%s\n", COLOR_RED, COLOR_RESET);
        printf("You need at least 5/6 (80%%) correct to unlock the Finale Sandbox.\n");
        printf("Please review the modules and try again!\n");
    }
}

// Finale Option: Code Sandbox with Auto-Evaluator
void showFinaleSandbox(void) {
    system("cls");
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
    typeWriter("        FINALE: CODE SANDBOX & EVALUATOR          \n", 5);
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
    printf("Congratulations on completing all curriculum modules!\n");
    printf("Select a coding challenge below to write your code:\n\n");

    printf("[1] Print Statement Challenge (Display 'C Programming')\n");
    printf("[2] Loop Challenge (Create a 'for' loop running 10 times)\n");
    printf("[3] Function Return Challenge (Return x multiplied by 2)\n");
    printf("[4] Array Access Challenge (Access 2nd element of 'scores')\n");
    printf("--------------------------------------------------\n");
    printf("Choose challenge (1-4): ");

    int subChoice = 0;
    if (scanf("%d", &subChoice) != 1) {
        clearBuffer();
        return;
    }
    clearBuffer();

    char userCode[200];
    system("cls");

    switch (subChoice) {
        case 1:
            printf("%s--- CHALLENGE 1: PRINT STATEMENT ---%s\n", COLOR_TITLE, COLOR_RESET);
            printf("Write a complete C line that prints 'C Programming' to console.\n");
            printf("Example format: printf(\"...\");\n\n");
            typeWriter("Your Code > ", 10);
            
            if (fgets(userCode, sizeof(userCode), stdin) != NULL) {
                userCode[strcspn(userCode, "\n")] = 0; // strip newline
                if (strstr(userCode, "printf") && strstr(userCode, "C Programming") && strstr(userCode, ";")) {
                    playSound(1);
                    printf("\n%s[✓] CODE APPROVED!%s Excellent syntax. You included printf, string arguments, and the required semicolon.\n\n", COLOR_TERM, COLOR_RESET);
                } else {
                    playSound(0);
                    printf("\n%s[X] CODE REVIEW FAILED%s\n", COLOR_RED, COLOR_RESET);
                    printf("--------------------------------------------------\n");
                    printf("%s• Diagnosis:%s Your code is missing one of these required elements:\n", COLOR_TITLE, COLOR_RESET);
                    printf("  1. Function 'printf'\n  2. String text \"C Programming\"\n  3. Ending semicolon ';'\n");
                    printf("%s• Correct Standard Syntax:%s\n  %sprintf(\"C Programming\");%s\n", COLOR_TERM, COLOR_RESET, COLOR_CODE, COLOR_RESET);
                    printf("%s• Tip:%s Always close C statements with semicolons and enclose text in double quotes.\n", COLOR_TITLE, COLOR_RESET);
                    printf("--------------------------------------------------\n\n");
                }
            }
            break;

        case 2:
            printf("%s--- CHALLENGE 2: FOR LOOP CREATION ---%s\n", COLOR_TITLE, COLOR_RESET);
            printf("Write the header for a 'for' loop counting from i = 0 up to i < 10.\n");
            printf("Example format: for(int i = 0; i < 10; i++)\n\n");
            typeWriter("Your Code > ", 10);
            
            if (fgets(userCode, sizeof(userCode), stdin) != NULL) {
                userCode[strcspn(userCode, "\n")] = 0;
                if (strstr(userCode, "for") && strstr(userCode, "i = 0") && strstr(userCode, "i < 10") && strstr(userCode, "i++")) {
                    playSound(1);
                    printf("\n%s[✓] CODE APPROVED!%s Perfect counter-controlled loop setup.\n\n", COLOR_TERM, COLOR_RESET);
                } else {
                    playSound(0);
                    printf("\n%s[X] CODE REVIEW FAILED%s\n", COLOR_RED, COLOR_RESET);
                    printf("--------------------------------------------------\n");
                    printf("%s• Diagnosis:%s A valid 'for' header requires 3 parts separated by semicolons:\n", COLOR_TITLE, COLOR_RESET);
                    printf("  1. Counter Initialization (int i = 0)\n  2. Stopping Condition (i < 10)\n  3. Increment Operator (i++)\n");
                    printf("%s• Correct Standard Syntax:%s\n  %sfor(int i = 0; i < 10; i++)%s\n", COLOR_TERM, COLOR_RESET, COLOR_CODE, COLOR_RESET);
                    printf("%s• Tip:%s Use semicolons inside the for-loop parentheses, NOT commas.\n", COLOR_TITLE, COLOR_RESET);
                    printf("--------------------------------------------------\n\n");
                }
            }
            break;

        case 3:
            printf("%s--- CHALLENGE 3: FUNCTION RETURN ---%s\n", COLOR_TITLE, COLOR_RESET);
            printf("Write a C return statement that hands back double the variable 'x'.\n");
            printf("Example format: return x * 2;\n\n");
            typeWriter("Your Code > ", 10);
            
            if (fgets(userCode, sizeof(userCode), stdin) != NULL) {
                userCode[strcspn(userCode, "\n")] = 0;
                if (strstr(userCode, "return") && (strstr(userCode, "x * 2") || strstr(userCode, "x*2") || strstr(userCode, "2 * x")) && strstr(userCode, ";")) {
                    playSound(1);
                    printf("\n%s[✓] CODE APPROVED!%s Excellent return logic.\n\n", COLOR_TERM, COLOR_RESET);
                } else {
                    playSound(0);
                    printf("\n%s[X] CODE REVIEW FAILED%s\n", COLOR_RED, COLOR_RESET);
                    printf("--------------------------------------------------\n");
                    printf("%s• Diagnosis:%s Ensure you include the 'return' keyword, multiplication operator '*', and trailing semicolon ';'.\n", COLOR_TITLE, COLOR_RESET);
                    printf("%s• Correct Standard Syntax:%s\n  %sreturn x * 2;%s\n", COLOR_TERM, COLOR_RESET, COLOR_CODE, COLOR_RESET);
                    printf("%s• Tip:%s The return statement sends data back to main() and immediately exits the function.\n", COLOR_TITLE, COLOR_RESET);
                    printf("--------------------------------------------------\n\n");
                }
            }
            break;

        case 4:
            printf("%s--- CHALLENGE 4: ARRAY ACCESS ---%s\n", COLOR_TITLE, COLOR_RESET);
            printf("Write the code expression to access the SECOND element of an array named 'scores'.\n");
            printf("Example format: scores[1]\n\n");
            typeWriter("Your Code > ", 10);
            
            if (fgets(userCode, sizeof(userCode), stdin) != NULL) {
                userCode[strcspn(userCode, "\n")] = 0;
                if (strstr(userCode, "scores[1]")) {
                    playSound(1);
                    printf("\n%s[✓] CODE APPROVED!%s Correct zero-based index targeting!\n\n", COLOR_TERM, COLOR_RESET);
                } else {
                    playSound(0);
                    printf("\n%s[X] CODE REVIEW FAILED%s\n", COLOR_RED, COLOR_RESET);
                    printf("--------------------------------------------------\n");
                    printf("%s• Diagnosis:%s Remember zero-indexing rules: 1st item = [0], 2nd item = [1].\n", COLOR_TITLE, COLOR_RESET);
                    printf("%s• Correct Standard Syntax:%s\n  %sscores[1]%s\n", COLOR_TERM, COLOR_RESET, COLOR_CODE, COLOR_RESET);
                    printf("%s• Tip:%s Using 'scores[2]' selects the THIRD item, not the second.\n", COLOR_TITLE, COLOR_RESET);
                    printf("--------------------------------------------------\n\n");
                }
            }
            break;

        default:
            printf("Invalid selection.\n");
            break;
    }
}

void showCredits(void) {
    system("cls");
    printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
    typeWriter("               PROGRAM CREDITS                    \n", 8);
    printf("%s==================================================%s\n\n", COLOR_HEADER, COLOR_RESET);
    
    typeWriter("  * Author:       Mirukyan\n", 12);
    typeWriter("  * GitHub:       https://github.com/Mirukyan\n", 12);
    typeWriter("  * Version:      v1.0.0 (Official Release)\n", 12);
    typeWriter("  * Language:     C Language (C99 Standard)\n\n", 12);
    
    printf("%sThank you for practicing! Press Enter to return to main menu...%s", COLOR_TERM, COLOR_RESET);
    clearBuffer();
    getchar();
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);

    int choice = 0;

    while (1) {
        system("cls");
        printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
        printf("%s   INTERACTIVE C STUDY GUIDE v1.0.0 (MIRUKYAN)    %s\n", COLOR_HEADER, COLOR_RESET);
        printf("%s==================================================%s\n", COLOR_HEADER, COLOR_RESET);
        printf("[1] Prelim: Problem Solving, Flowchart & Pseudocode\n");
        printf("[2] Midterm: Sequential, Selection & Loops\n");
        printf("[3] Semi Finals: Functions & Scope\n");
        printf("[4] Finals: Arrays & Traversal\n");
        printf("[5] Comprehensive Practice (All Topics - Exam Mode)\n");
        
        if (hasCompletedAllTopics) {
            printf("%s[6] [UNLOCKED FINALE] Free-Code Sandbox & Evaluator%s\n", COLOR_TERM, COLOR_RESET);
        } else {
            printf("[6] [LOCKED] Finale Sandbox (Score 80%% on Option 5 to unlock)\n");
        }
        
        printf("[7] View Credits\n");
        printf("[0] Exit Program\n");
        printf("--------------------------------------------------\n");
        printf("Select period (0-7): ");

        if (scanf("%d", &choice) != 1) {
            playSound(0);
            printf("\n%s[!] Invalid input. Enter a number.%s\n\n", COLOR_RED, COLOR_RESET);
            clearBuffer();
            Sleep(1000);
            continue;
        }

        switch (choice) {
            case 1: showPrelim(); break;
            case 2: showMidterm(); break;
            case 3: showSemiFinals(); break;
            case 4: showFinals(); break;
            case 5: showComprehensivePractice(); break;
            case 6:
                if (hasCompletedAllTopics) {
                    showFinaleSandbox();
                } else {
                    playSound(0);
                    printf("\n%s[!] Finale is locked! Complete Option [5] with at least 80%% score first.%s\n\n", COLOR_RED, COLOR_RESET);
                }
                break;
            case 7: showCredits(); continue;
            case 0:
                system("cls");
                typeWriter("Exiting program. Happy coding and good luck with your studies!\n", 10);
                return 0;
            default:
                playSound(0);
                printf("\n%s[!] Invalid selection. Choose 0-7.%s\n\n", COLOR_RED, COLOR_RESET);
                Sleep(1000);
                break;
        }

        printf("\n--------------------------------------------------\n");
        printf("Press Enter to return to the Main Menu...");
        clearBuffer();
        getchar();
    }

    return 0;
}