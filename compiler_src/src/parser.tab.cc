// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "../inc/parser.tab.h"


// Unqualified %code blocks.
#line 19 "src/bison/parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

  Node* root;
  extern int yylineno;

#line 54 "src/parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "src/parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_content: // class_content
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_head: // method_head
      case symbol_kind::S_method_body: // method_body
      case symbol_kind::S_method_arguments: // method_arguments
      case symbol_kind::S_method_content: // method_content
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_lst: // expression_lst
      case symbol_kind::S_expression_operators: // expression_operators
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_id: // id
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_SEP: // SEP
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_LS: // LS
      case symbol_kind::S_RS: // RS
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_DELI: // DELI
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_ADD_OP: // ADD_OP
      case symbol_kind::S_SUB_OP: // SUB_OP
      case symbol_kind::S_NOT_OP: // NOT_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_ASSIGN_OP: // ASSIGN_OP
      case symbol_kind::S_ATTR_OP: // ATTR_OP
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_content: // class_content
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_head: // method_head
      case symbol_kind::S_method_body: // method_body
      case symbol_kind::S_method_arguments: // method_arguments
      case symbol_kind::S_method_content: // method_content
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_lst: // expression_lst
      case symbol_kind::S_expression_operators: // expression_operators
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_id: // id
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_SEP: // SEP
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_LS: // LS
      case symbol_kind::S_RS: // RS
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_DELI: // DELI
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_ADD_OP: // ADD_OP
      case symbol_kind::S_SUB_OP: // SUB_OP
      case symbol_kind::S_NOT_OP: // NOT_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_ASSIGN_OP: // ASSIGN_OP
      case symbol_kind::S_ATTR_OP: // ATTR_OP
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_content: // class_content
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_head: // method_head
      case symbol_kind::S_method_body: // method_body
      case symbol_kind::S_method_arguments: // method_arguments
      case symbol_kind::S_method_content: // method_content
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_lst: // expression_lst
      case symbol_kind::S_expression_operators: // expression_operators
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_id: // id
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_SEP: // SEP
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_LS: // LS
      case symbol_kind::S_RS: // RS
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_DELI: // DELI
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_ADD_OP: // ADD_OP
      case symbol_kind::S_SUB_OP: // SUB_OP
      case symbol_kind::S_NOT_OP: // NOT_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_ASSIGN_OP: // ASSIGN_OP
      case symbol_kind::S_ATTR_OP: // ATTR_OP
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_content: // class_content
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_head: // method_head
      case symbol_kind::S_method_body: // method_body
      case symbol_kind::S_method_arguments: // method_arguments
      case symbol_kind::S_method_content: // method_content
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_lst: // expression_lst
      case symbol_kind::S_expression_operators: // expression_operators
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_id: // id
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< int > (that.value);
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_SEP: // SEP
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_LS: // LS
      case symbol_kind::S_RS: // RS
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_DELI: // DELI
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_ADD_OP: // ADD_OP
      case symbol_kind::S_SUB_OP: // SUB_OP
      case symbol_kind::S_NOT_OP: // NOT_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_ASSIGN_OP: // ASSIGN_OP
      case symbol_kind::S_ATTR_OP: // ATTR_OP
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_content: // class_content
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_head: // method_head
      case symbol_kind::S_method_body: // method_body
      case symbol_kind::S_method_arguments: // method_arguments
      case symbol_kind::S_method_content: // method_content
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_lst: // expression_lst
      case symbol_kind::S_expression_operators: // expression_operators
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_id: // id
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_SEP: // SEP
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_LS: // LS
      case symbol_kind::S_RS: // RS
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_DELI: // DELI
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_ADD_OP: // ADD_OP
      case symbol_kind::S_SUB_OP: // SUB_OP
      case symbol_kind::S_NOT_OP: // NOT_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_ASSIGN_OP: // ASSIGN_OP
      case symbol_kind::S_ATTR_OP: // ATTR_OP
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: main_class class_declaration_list "end of file"
#line 55 "src/bison/parser.yy"
                                          { 
      root = new SyRoot("root", "", yylineno); 
      root->children.push_back(yystack_[2].value.as < Node * > ());
      root->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 862 "src/parser.tab.cc"
    break;

  case 3: // root: main_class "end of file"
#line 60 "src/bison/parser.yy"
                   {
      root = new SyRoot("root", "", yylineno); 
      root->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 871 "src/parser.tab.cc"
    break;

  case 4: // main_class: PUBLIC CLASS id LB PUBLIC STATIC VOID MAIN LP STRING LS RS id RP LB statement_list RB RB
#line 67 "src/bison/parser.yy"
                                                                                             {
    yylhs.value.as < Node * > () = new SyMainClass("main_class", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 882 "src/parser.tab.cc"
    break;

  case 5: // class_declaration_list: class_declaration
#line 76 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 888 "src/parser.tab.cc"
    break;

  case 6: // class_declaration_list: class_declaration_list class_declaration_list
#line 77 "src/bison/parser.yy"
                                                  {
    yylhs.value.as < Node * > () = new Node("class_decl_lst", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 898 "src/parser.tab.cc"
    break;

  case 7: // class_declaration: CLASS id LB class_content RB
#line 85 "src/bison/parser.yy"
                                 {
    yylhs.value.as < Node * > () = new SyClass("class_decl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 908 "src/parser.tab.cc"
    break;

  case 8: // class_content: var_declaration_list
#line 93 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 914 "src/parser.tab.cc"
    break;

  case 9: // class_content: method_declaration_list
#line 94 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 920 "src/parser.tab.cc"
    break;

  case 10: // class_content: class_content class_content
#line 95 "src/bison/parser.yy"
                                {
    yylhs.value.as < Node * > () = new Node("class_content", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 930 "src/parser.tab.cc"
    break;

  case 11: // var_declaration_list: var_declaration
#line 103 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 936 "src/parser.tab.cc"
    break;

  case 12: // var_declaration_list: var_declaration var_declaration_list
#line 104 "src/bison/parser.yy"
                                         {
    yylhs.value.as < Node * > () = new Node("var_decl_lst", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 946 "src/parser.tab.cc"
    break;

  case 13: // var_declaration: type id DELI
#line 112 "src/bison/parser.yy"
                 {
    yylhs.value.as < Node * > () = new SyVariable("var_decl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 956 "src/parser.tab.cc"
    break;

  case 14: // method_declaration_list: method_declaration
#line 120 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 962 "src/parser.tab.cc"
    break;

  case 15: // method_declaration_list: method_declaration_list method_declaration_list
#line 121 "src/bison/parser.yy"
                                                    {
    yylhs.value.as < Node * > () = new Node("method_decl_lst", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 972 "src/parser.tab.cc"
    break;

  case 16: // method_declaration: method_head LP RP method_body
#line 129 "src/bison/parser.yy"
                                  {
    yylhs.value.as < Node * > () = new SyMethod("method_decl", "declaration", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 982 "src/parser.tab.cc"
    break;

  case 17: // method_declaration: method_head LP method_arguments RP method_body
#line 134 "src/bison/parser.yy"
                                                   {
    yylhs.value.as < Node * > () = new SyMethod("method_decl", "declaration", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 993 "src/parser.tab.cc"
    break;

  case 18: // method_head: PUBLIC type id
#line 143 "src/bison/parser.yy"
                   {
    yylhs.value.as < Node * > () = new Node("method_decl", "head", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1003 "src/parser.tab.cc"
    break;

  case 19: // method_body: LB RETURN expression_operators DELI RB
#line 151 "src/bison/parser.yy"
                                           {
    yylhs.value.as < Node * > () = new Node("method_decl", "body", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1012 "src/parser.tab.cc"
    break;

  case 20: // method_body: LB method_content RETURN expression_operators DELI RB
#line 155 "src/bison/parser.yy"
                                                          {
    yylhs.value.as < Node * > () = new Node("method_decl", "body", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1022 "src/parser.tab.cc"
    break;

  case 21: // method_arguments: type id
#line 163 "src/bison/parser.yy"
            {
    yylhs.value.as < Node * > () = new SyVariable("method_arg", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1032 "src/parser.tab.cc"
    break;

  case 22: // method_arguments: method_arguments SEP method_arguments
#line 168 "src/bison/parser.yy"
                                          {
    yylhs.value.as < Node * > () = new Node("method_arg_lst", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1042 "src/parser.tab.cc"
    break;

  case 23: // method_content: var_declaration
#line 176 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1048 "src/parser.tab.cc"
    break;

  case 24: // method_content: statement
#line 177 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1054 "src/parser.tab.cc"
    break;

  case 25: // method_content: method_content method_content
#line 178 "src/bison/parser.yy"
                                  {
    yylhs.value.as < Node * > () = new Node("method_content", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1064 "src/parser.tab.cc"
    break;

  case 26: // type: INT LS RS
#line 186 "src/bison/parser.yy"
              { yylhs.value.as < Node * > () = new Node("type", "int_arr", yylineno); }
#line 1070 "src/parser.tab.cc"
    break;

  case 27: // type: BOOLEAN
#line 187 "src/bison/parser.yy"
            { yylhs.value.as < Node * > () = new Node("type", "boolean", yylineno); }
#line 1076 "src/parser.tab.cc"
    break;

  case 28: // type: INT
#line 188 "src/bison/parser.yy"
        { yylhs.value.as < Node * > () = new Node("type", "int", yylineno); }
#line 1082 "src/parser.tab.cc"
    break;

  case 29: // type: id
#line 189 "src/bison/parser.yy"
       { 
    yylhs.value.as < Node * > () = new Node("type", "id", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1091 "src/parser.tab.cc"
    break;

  case 30: // statement_list: statement
#line 196 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1097 "src/parser.tab.cc"
    break;

  case 31: // statement_list: statement_list statement_list
#line 197 "src/bison/parser.yy"
                                  {
    yylhs.value.as < Node * > () = new Node("statement_lst", "", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1107 "src/parser.tab.cc"
    break;

  case 32: // statement: LB statement_list RB
#line 205 "src/bison/parser.yy"
                         {
    yylhs.value.as < Node * > () = new Node("statement", "block", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1116 "src/parser.tab.cc"
    break;

  case 33: // statement: LB RB
#line 209 "src/bison/parser.yy"
          {
    yylhs.value.as < Node * > () = new SyEmpty("statement", "empty", yylineno); 
  }
#line 1124 "src/parser.tab.cc"
    break;

  case 34: // statement: IF LP expression_operators RP statement
#line 212 "src/bison/parser.yy"
                                            {
    yylhs.value.as < Node * > () = new SyIf("statement", "if", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1134 "src/parser.tab.cc"
    break;

  case 35: // statement: IF LP expression_operators RP statement ELSE statement
#line 217 "src/bison/parser.yy"
                                                           {
    yylhs.value.as < Node * > () = new SyIfElse("statement", "if-else", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1145 "src/parser.tab.cc"
    break;

  case 36: // statement: WHILE LP expression_operators RP statement
#line 223 "src/bison/parser.yy"
                                               {
    yylhs.value.as < Node * > () = new SyWhile("statement", "while", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1155 "src/parser.tab.cc"
    break;

  case 37: // statement: PRINT LP expression_operators RP DELI
#line 228 "src/bison/parser.yy"
                                          {
    yylhs.value.as < Node * > () = new SyPrint("statement", "print", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1164 "src/parser.tab.cc"
    break;

  case 38: // statement: id ASSIGN_OP expression_operators DELI
#line 232 "src/bison/parser.yy"
                                           {
    yylhs.value.as < Node * > () = new SyAssign("statement", "assign", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1174 "src/parser.tab.cc"
    break;

  case 39: // statement: id LS expression_operators RS ASSIGN_OP expression_operators DELI
#line 237 "src/bison/parser.yy"
                                                                      {
    yylhs.value.as < Node * > () = new SyAssignArr("statement", "assign_arr", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1185 "src/parser.tab.cc"
    break;

  case 40: // expression_lst: expression_lst SEP expression_lst
#line 246 "src/bison/parser.yy"
                                      {
    yylhs.value.as < Node * > () = new SyExpressionList("expression_lst", "sep", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1195 "src/parser.tab.cc"
    break;

  case 41: // expression_lst: expression_operators
#line 251 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1201 "src/parser.tab.cc"
    break;

  case 42: // expression_operators: expression_operators ADD_OP expression_operators
#line 255 "src/bison/parser.yy"
                                                     {
    yylhs.value.as < Node * > () = new SyOperator("expression", "add", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1211 "src/parser.tab.cc"
    break;

  case 43: // expression_operators: expression_operators SUB_OP expression_operators
#line 260 "src/bison/parser.yy"
                                                     {
    yylhs.value.as < Node * > () = new SyOperator("expression", "sub", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1221 "src/parser.tab.cc"
    break;

  case 44: // expression_operators: expression_operators MULT_OP expression_operators
#line 265 "src/bison/parser.yy"
                                                      {
    yylhs.value.as < Node * > () = new SyOperator("expression", "mult", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1231 "src/parser.tab.cc"
    break;

  case 45: // expression_operators: expression_operators AND_OP expression_operators
#line 270 "src/bison/parser.yy"
                                                     {
    yylhs.value.as < Node * > () = new SyOperator("expression", "and", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1241 "src/parser.tab.cc"
    break;

  case 46: // expression_operators: expression_operators OR_OP expression_operators
#line 275 "src/bison/parser.yy"
                                                    {
    yylhs.value.as < Node * > () = new SyOperator("expression", "or", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1251 "src/parser.tab.cc"
    break;

  case 47: // expression_operators: expression_operators EQ_OP expression_operators
#line 280 "src/bison/parser.yy"
                                                    {
    yylhs.value.as < Node * > () = new SyOperator("expression", "eq", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1261 "src/parser.tab.cc"
    break;

  case 48: // expression_operators: expression_operators GT_OP expression_operators
#line 285 "src/bison/parser.yy"
                                                    {
    yylhs.value.as < Node * > () = new SyOperator("expression", "gt", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1271 "src/parser.tab.cc"
    break;

  case 49: // expression_operators: expression_operators LT_OP expression_operators
#line 290 "src/bison/parser.yy"
                                                    {
    yylhs.value.as < Node * > () = new SyOperator("expression", "lt", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1281 "src/parser.tab.cc"
    break;

  case 50: // expression_operators: expression
#line 295 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1287 "src/parser.tab.cc"
    break;

  case 51: // expression: expression LS expression_operators RS
#line 299 "src/bison/parser.yy"
                                          {
    yylhs.value.as < Node * > () = new SyArrayPull("expression", "arr", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1297 "src/parser.tab.cc"
    break;

  case 52: // expression: expression ATTR_OP LENGTH
#line 304 "src/bison/parser.yy"
                              {
    yylhs.value.as < Node * > () = new SyLength("expression", "length", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1306 "src/parser.tab.cc"
    break;

  case 53: // expression: expression ATTR_OP id LP expression_lst RP
#line 308 "src/bison/parser.yy"
                                               {
    yylhs.value.as < Node * > () = new SyAttribute("expression", "attr_exp", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1317 "src/parser.tab.cc"
    break;

  case 54: // expression: expression ATTR_OP id LP RP
#line 314 "src/bison/parser.yy"
                                {
    yylhs.value.as < Node * > () = new SyAttribute("expression", "attr", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1327 "src/parser.tab.cc"
    break;

  case 55: // expression: LP expression_operators RP
#line 319 "src/bison/parser.yy"
                               {
    yylhs.value.as < Node * > () = new SyParenthesis("expression", "brackets", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1336 "src/parser.tab.cc"
    break;

  case 56: // expression: NUMBER
#line 323 "src/bison/parser.yy"
           { yylhs.value.as < Node * > () = new SyNumber("number", std::to_string(yystack_[0].value.as < int > ()),  yylineno); }
#line 1342 "src/parser.tab.cc"
    break;

  case 57: // expression: BOOL
#line 324 "src/bison/parser.yy"
         {
    std::string val;
    if (yystack_[0].value.as < bool > ()) {
      val = "true";
    } else {
      val = "false";
    }

    yylhs.value.as < Node * > () = new SyBoolean("bool", val, yylineno);
  }
#line 1357 "src/parser.tab.cc"
    break;

  case 58: // expression: id
#line 334 "src/bison/parser.yy"
       {
    yylhs.value.as < Node * > () = new SyIdentifier("expression", "id", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1366 "src/parser.tab.cc"
    break;

  case 59: // expression: THIS
#line 338 "src/bison/parser.yy"
         {
    yylhs.value.as < Node * > () = new SyThis("expression", "this", yylineno);
  }
#line 1374 "src/parser.tab.cc"
    break;

  case 60: // expression: NEW INT LS expression_operators RS
#line 341 "src/bison/parser.yy"
                                       {
    yylhs.value.as < Node * > () = new SyArrayInit("expression", "arr", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1383 "src/parser.tab.cc"
    break;

  case 61: // expression: NEW id LP RP
#line 345 "src/bison/parser.yy"
                 {
    yylhs.value.as < Node * > () = new SyObjectInit("expression", "init", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1392 "src/parser.tab.cc"
    break;

  case 62: // expression: NOT_OP expression
#line 349 "src/bison/parser.yy"
                      {
    yylhs.value.as < Node * > () = new SyNot("expression", "not", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1401 "src/parser.tab.cc"
    break;

  case 63: // id: ID
#line 356 "src/bison/parser.yy"
       {
    yylhs.value.as < Node * > () = new Node("id", yystack_[0].value.as < std::string > (),  yylineno);
  }
#line 1409 "src/parser.tab.cc"
    break;


#line 1413 "src/parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -49;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      -6,    -2,    22,     7,    17,   -49,   -49,    17,    11,   -49,
     -49,    39,    43,   -49,    46,     9,    52,    55,   -49,    68,
       5,   253,   -49,     5,    82,   -49,    95,    17,   -49,    93,
      97,    17,   -49,    52,   -49,    82,   224,    89,    98,   -49,
     -49,   104,    33,    17,   -49,   112,   184,   -49,     5,   104,
     -49,   106,   241,   215,   118,   119,   122,   -49,   194,   -49,
       8,   117,   -49,   129,   -49,   249,   -49,     8,   215,    47,
     -49,   -49,   -49,   215,   277,    -1,   -49,   215,   215,   215,
     215,   237,   215,   215,   121,   -49,   272,    19,   130,   131,
      -1,   133,   215,   215,   215,   215,   215,   215,   215,   215,
     215,     2,    76,    96,   116,   290,   127,   303,    17,   -49,
     215,   137,   -49,   250,   250,    56,    56,    56,    56,    56,
      56,   140,   -49,   139,   272,   272,   141,   143,   124,   -49,
     161,   151,   -49,   -49,   205,   -49,   144,   -49,   -49,   215,
     164,   -49,   -49,    59,   327,   272,   316,   272,   215,   -49,
     -49,   -49,   268,   170,   167,   -49
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     1,     3,     0,     0,     5,
      63,     0,     0,     2,     6,     0,     0,     0,    27,    28,
       0,     0,     8,    11,     9,    14,     0,     0,    29,     0,
       0,     0,     7,    10,    12,    15,     0,     0,     0,    26,
      18,     0,     0,     0,    13,     0,     0,    16,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    23,     0,    24,
      29,    22,    17,     0,    33,     0,    30,     0,     0,     0,
      59,    56,    57,     0,     0,    50,    58,     0,     0,     0,
       0,    25,     0,     0,     0,    32,    31,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    19,    42,    43,    45,    46,    44,    47,    49,
      48,     0,    52,     0,     0,     0,     0,     0,     0,    38,
       0,     0,    61,    51,     0,    36,    34,    37,    20,     0,
       0,    60,    54,     0,    41,     0,     0,     0,     0,    53,
      35,    39,     0,    40,     0,     4
  };

  const short
  parser::yypgoto_[] =
  {
     -49,   -49,   -49,   180,   -49,   177,   163,   -44,     6,   -49,
     -49,   145,   147,   150,   -15,   -48,   -45,    50,    -8,   128,
      -4
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,    14,     9,    33,    22,    23,    24,    25,
      26,    47,    42,    81,    27,    86,    66,   143,   144,    75,
      76
  };

  const unsigned char
  parser::yytable_[] =
  {
      11,    59,    57,    12,    65,    31,   122,     6,    18,   100,
       1,    13,    28,    59,    57,     4,    28,    28,    82,    28,
      19,    43,     5,    37,     7,    17,   109,    40,     7,    28,
      35,    10,    28,    43,    10,   101,    59,    57,    48,    50,
      49,    35,    60,    83,    28,    74,    10,    15,    67,    92,
      93,    16,    94,    95,    60,    18,    96,    97,    98,    99,
      87,    67,    88,     7,   148,    89,   149,    19,    20,   102,
     103,   104,   105,    29,   106,   107,    10,    60,    30,   135,
     136,    10,    67,   124,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    96,    97,    98,    99,   123,    20,   152,
     150,    36,   131,   125,   130,    38,    92,    93,    39,    94,
      95,    44,    46,    96,    97,    98,    99,    45,    51,    63,
      67,    67,    48,   126,    77,    78,    92,    93,    79,    94,
      95,   146,   108,    96,    97,    98,    99,   111,   128,    84,
     110,    67,   112,    67,   132,   134,    92,    93,    67,    94,
      95,   133,   138,    96,    97,    98,    99,    92,    93,   139,
      94,    95,   141,   137,    96,    97,    98,    99,   140,   145,
      92,    93,   147,    94,    95,   148,   155,    96,    97,    98,
      99,    92,    93,     8,    94,    95,    34,    18,    96,    97,
      98,    99,    52,    21,    62,    61,    58,    18,   153,    19,
       0,    90,    52,     0,    53,     0,     0,    54,    55,    19,
      56,    68,   142,    10,    80,     0,     0,    54,    55,    69,
      56,    68,     0,    10,     0,     0,    70,    18,     0,    69,
       0,    41,    71,    72,    10,     0,    70,    73,     0,    19,
      18,     0,    71,    72,    10,    52,     0,    73,     0,    52,
      64,     0,    19,    10,     0,     0,    18,    52,    85,     0,
      54,    55,    32,    56,    54,    55,    10,    56,    19,    20,
      10,     0,    54,    55,     0,    56,    52,   154,    10,     0,
      52,     0,    10,    94,    95,     0,     0,    96,    97,    98,
      99,    54,    55,     0,    56,    54,    55,    10,    56,    91,
       0,    10,     0,     0,     0,     0,     0,    92,    93,     0,
      94,    95,   127,     0,    96,    97,    98,    99,     0,     0,
      92,    93,     0,    94,    95,   129,     0,    96,    97,    98,
      99,     0,     0,    92,    93,     0,    94,    95,   151,     0,
      96,    97,    98,    99,     0,     0,    92,    93,     0,    94,
      95,     0,     0,    96,    97,    98,    99,    92,    93,     0,
      94,    95,     0,     0,    96,    97,    98,    99
  };

  const short
  parser::yycheck_[] =
  {
       4,    46,    46,     7,    52,    20,     4,     0,     3,    10,
      16,     0,    16,    58,    58,    17,    20,    21,    10,    23,
      15,    36,     0,    27,    17,    16,     7,    31,    17,    33,
      24,    29,    36,    48,    29,    36,    81,    81,     5,    43,
       7,    35,    46,    35,    48,    53,    29,     8,    52,    30,
      31,     8,    33,    34,    58,     3,    37,    38,    39,    40,
      68,    65,    15,    17,     5,    69,     7,    15,    16,    77,
      78,    79,    80,    18,    82,    83,    29,    81,    10,   124,
     125,    29,    86,     7,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    37,    38,    39,    40,   101,    16,   147,
     145,     6,   110,     7,   108,    12,    30,    31,    11,    33,
      34,    22,     8,    37,    38,    39,    40,    19,     6,    13,
     124,   125,     5,     7,     6,     6,    30,    31,     6,    33,
      34,   139,    11,    37,    38,    39,    40,     6,    11,    10,
      10,   145,     9,   147,     7,     6,    30,    31,   152,    33,
      34,    11,     9,    37,    38,    39,    40,    30,    31,    35,
      33,    34,    11,    22,    37,    38,    39,    40,     7,    25,
      30,    31,     8,    33,    34,     5,     9,    37,    38,    39,
      40,    30,    31,     3,    33,    34,    23,     3,    37,    38,
      39,    40,     8,    16,    49,    48,    46,     3,   148,    15,
      -1,    73,     8,    -1,    20,    -1,    -1,    23,    24,    15,
      26,     6,     7,    29,    20,    -1,    -1,    23,    24,    14,
      26,     6,    -1,    29,    -1,    -1,    21,     3,    -1,    14,
      -1,     7,    27,    28,    29,    -1,    21,    32,    -1,    15,
       3,    -1,    27,    28,    29,     8,    -1,    32,    -1,     8,
       9,    -1,    15,    29,    -1,    -1,     3,     8,     9,    -1,
      23,    24,     9,    26,    23,    24,    29,    26,    15,    16,
      29,    -1,    23,    24,    -1,    26,     8,     9,    29,    -1,
       8,    -1,    29,    33,    34,    -1,    -1,    37,    38,    39,
      40,    23,    24,    -1,    26,    23,    24,    29,    26,    22,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    22,    -1,    37,    38,    39,    40,    -1,    -1,
      30,    31,    -1,    33,    34,    22,    -1,    37,    38,    39,
      40,    -1,    -1,    30,    31,    -1,    33,    34,    22,    -1,
      37,    38,    39,    40,    -1,    -1,    30,    31,    -1,    33,
      34,    -1,    -1,    37,    38,    39,    40,    30,    31,    -1,
      33,    34,    -1,    -1,    37,    38,    39,    40
  };

  const signed char
  parser::yystos_[] =
  {
       0,    16,    42,    43,    17,     0,     0,    17,    44,    45,
      29,    61,    61,     0,    44,     8,     8,    16,     3,    15,
      16,    46,    47,    48,    49,    50,    51,    55,    61,    18,
      10,    55,     9,    46,    47,    49,     6,    61,    12,    11,
      61,     7,    53,    55,    22,    19,     8,    52,     5,     7,
      61,     6,     8,    20,    23,    24,    26,    48,    54,    57,
      61,    53,    52,    13,     9,    56,    57,    61,     6,    14,
      21,    27,    28,    32,    59,    60,    61,     6,     6,     6,
      20,    54,    10,    35,    10,     9,    56,    59,    15,    61,
      60,    22,    30,    31,    33,    34,    37,    38,    39,    40,
      10,    36,    59,    59,    59,    59,    59,    59,    11,     7,
      10,     6,     9,    59,    59,    59,    59,    59,    59,    59,
      59,    59,     4,    61,     7,     7,     7,    22,    11,    22,
      61,    59,     7,    11,     6,    57,    57,    22,     9,    35,
       7,    11,     7,    58,    59,    25,    59,     8,     5,     7,
      57,    22,    56,    58,     9,     9
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    42,    43,    44,    44,    45,    46,    46,
      46,    47,    47,    48,    49,    49,    50,    50,    51,    52,
      52,    53,    53,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     2,    18,     1,     2,     5,     1,     1,
       2,     1,     2,     3,     1,     2,     4,     5,     3,     5,
       6,     2,     3,     1,     1,     2,     3,     1,     1,     1,
       1,     2,     3,     2,     5,     7,     5,     5,     4,     7,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     4,     3,     6,     5,     3,     1,     1,     1,     1,
       5,     4,     2,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "BOOLEAN", "LENGTH",
  "SEP", "LP", "RP", "LB", "RB", "LS", "RS", "VOID", "STRING", "NEW",
  "INT", "PUBLIC", "CLASS", "STATIC", "MAIN", "RETURN", "THIS", "DELI",
  "WHILE", "IF", "ELSE", "PRINT", "NUMBER", "BOOL", "ID", "ADD_OP",
  "SUB_OP", "NOT_OP", "AND_OP", "OR_OP", "ASSIGN_OP", "ATTR_OP", "MULT_OP",
  "EQ_OP", "LT_OP", "GT_OP", "$accept", "root", "main_class",
  "class_declaration_list", "class_declaration", "class_content",
  "var_declaration_list", "var_declaration", "method_declaration_list",
  "method_declaration", "method_head", "method_body", "method_arguments",
  "method_content", "type", "statement_list", "statement",
  "expression_lst", "expression_operators", "expression", "id", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    55,    55,    60,    67,    76,    77,    85,    93,    94,
      95,   103,   104,   112,   120,   121,   129,   134,   143,   151,
     155,   163,   168,   176,   177,   178,   186,   187,   188,   189,
     196,   197,   205,   209,   212,   217,   223,   228,   232,   237,
     246,   251,   255,   260,   265,   270,   275,   280,   285,   290,
     295,   299,   304,   308,   314,   319,   323,   324,   334,   338,
     341,   345,   349,   356
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2016 "src/parser.tab.cc"

