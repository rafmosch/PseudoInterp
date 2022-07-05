#pragma once
#include <string>
#include <vector>
#include <array>

enum class TokenType { // Enumeration of all token types
    L_PAREN,
    R_PAREN,
    L_SQ_BRACKET,
    R_SQ_BRACKET,
    DOT,
    TILDA,
    CIRCUMFLEX,
    DOUBLE_PLUS,
    DOUBLE_MINUS,
    PLUS,
    MINUS,
    STAR,
    FORW_SLASH,
    PERCENT,
    DOUBLE_AMP,
    AMP,
    DOUBLE_VERT_SLASH,
    VERT_SLASH,
    EXMARK,
    EQ,
    DOUBLE_EQ,
    NOT_EQ,
    LESS_EQ,
    GRE_EQ,
    LESS,
    GRE,
    LSHFT,
    RSHFT,
    INT_LIT,
    ID,
    WHSPACE,
    TAB,
    NEWLINE,
    OUTPUT,
    EOFILE,
    UNKNOWN
};

class TokenDescriptor { // Connects a lexeme (string) to a token type
public:
    TokenDescriptor();
    TokenDescriptor(const std::string&, TokenType);
    std::string getLexeme();
    size_t getLen();
    TokenType getType();
protected:
    std::string lexeme = "";
    TokenType type = TokenType::UNKNOWN;

};

class Token : public TokenDescriptor { // Used for actual tokens found in the input string
public:
    Token() {}
    Token(const std::string&, TokenType, int);
    int getPos();
private:
    int pos = 0; // The position of the token in the input string
};

class Lexer {
public:
    Lexer();
    Lexer(const std::string&);
    void setInput(const std::string&);
    Token getCurrToken();
    Token lookForw(int);
    void scanToken();
    void lexInput();
private:
    std::vector<Token> tokenList;
    int tokenListIndex = 0;
    std::string originalStr = "";
    std::string str = "";
    std::vector<TokenDescriptor> fixedTokenList = { // A list of keywords, relating lexeme to token type
            TokenDescriptor("+", TokenType::PLUS),
            TokenDescriptor("-", TokenType::MINUS),
            TokenDescriptor("*", TokenType::STAR),
            TokenDescriptor("/", TokenType::FORW_SLASH),
            TokenDescriptor("(", TokenType::L_PAREN),
            TokenDescriptor(")", TokenType::R_PAREN),
            TokenDescriptor("%", TokenType::PERCENT),
            TokenDescriptor("||", TokenType::DOUBLE_VERT_SLASH),
            TokenDescriptor("&&", TokenType::DOUBLE_AMP),
            TokenDescriptor("=", TokenType::EQ),
            TokenDescriptor("==", TokenType::DOUBLE_EQ),
            TokenDescriptor("<<", TokenType::LSHFT),
            TokenDescriptor(">>", TokenType::RSHFT),
            TokenDescriptor("!=", TokenType::NOT_EQ),
            TokenDescriptor("<=", TokenType::LESS_EQ),
            TokenDescriptor(">=", TokenType::GRE_EQ),
            TokenDescriptor("<", TokenType::LESS),
            TokenDescriptor(">", TokenType::GRE),
            TokenDescriptor("\t", TokenType::TAB),
            TokenDescriptor("\n", TokenType::NEWLINE),
            TokenDescriptor("output", TokenType::OUTPUT),
    };
    std::string preprocessStr(const std::string&);
    int posToLine(int);
};

