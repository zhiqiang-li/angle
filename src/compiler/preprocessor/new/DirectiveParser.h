//
// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#ifndef COMPILER_PREPROCESSOR_DIRECTIVE_PARSER_H_
#define COMPILER_PREPROCESSOR_DIRECTIVE_PARSER_H_

#include "Lexer.h"
#include "pp_utils.h"

namespace pp
{

class Tokenizer;

class DirectiveParser : public Lexer
{
  public:
    DirectiveParser(Tokenizer* tokenizer) : mTokenizer(tokenizer) { }

    virtual void lex(Token* token);

  private:
    PP_DISALLOW_COPY_AND_ASSIGN(DirectiveParser);

    void parseDirective(Token* token);
    void parseDefine(Token* token);
    void parseUndef(Token* token);
    void parseIf(Token* token);
    void parseIfdef(Token* token);
    void parseIfndef(Token* token);
    void parseElse(Token* token);
    void parseElif(Token* token);
    void parseEndif(Token* token);
    void parseError(Token* token);
    void parsePragma(Token* token);
    void parseExtension(Token* token);
    void parseVersion(Token* token);
    void parseLine(Token* token);

    Tokenizer* mTokenizer;
};

}  // namespace pp
#endif  // COMPILER_PREPROCESSOR_DIRECTIVE_PARSER_H_
