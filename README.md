# Lexical-Analyser-and-Parser-Generator
Lexical analysis:
The first phase of a compiler is called the lexical analyser or scanning. The lexical analyser reads the stream of characters making up the source program and groups the characters into meaningful sequences called lexemes. For each lexeme, the lexical analyser produces as output a token of the form
(token name, attribute value)
that it passes on to the subsequent phase, syntax analysis. In the token, the first part is the token name is an abstract symbol that is used during syntax analysis and the second part, attribute value points to an entry in the symbol table for this token, the symbol table information is passed on to the semantic analysis and the code generation.

Syntax Analysis:
The second phase of the compiler is the Syntax Analysis (Parsing). It uses the first components of the tokens produced by the lexical analyser to create a tree-like intermediate representation that depicts the grammatical structure of the token stream. In a Syntax tree, the interior node represents the operation and the child of the node represents arguments of the operation.

 The Parser used in the implementation: LL(1) Parser.
The First ‘L’ in LL(1) stands scanning the inputs from left to right, the second ‘L’ stands for producing the left most derivation, and the ‘1’  for using the one input symbol of look ahead each step to make parsing action decisions.



