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
#line 18 "src/bison/parser.yy"

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
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operator: // operator
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
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
      case symbol_kind::S_NOT_OP: // NOT_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_ASSIGN_OP: // ASSIGN_OP
      case symbol_kind::S_ATTR_OP: // ATTR_OP
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
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operator: // operator
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
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
      case symbol_kind::S_NOT_OP: // NOT_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_ASSIGN_OP: // ASSIGN_OP
      case symbol_kind::S_ATTR_OP: // ATTR_OP
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
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operator: // operator
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
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
      case symbol_kind::S_NOT_OP: // NOT_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_ASSIGN_OP: // ASSIGN_OP
      case symbol_kind::S_ATTR_OP: // ATTR_OP
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
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operator: // operator
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
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
      case symbol_kind::S_NOT_OP: // NOT_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_ASSIGN_OP: // ASSIGN_OP
      case symbol_kind::S_ATTR_OP: // ATTR_OP
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
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operator: // operator
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
      case symbol_kind::S_MULT_OP: // MULT_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_LT_OP: // LT_OP
      case symbol_kind::S_GT_OP: // GT_OP
      case symbol_kind::S_NOT_OP: // NOT_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_ASSIGN_OP: // ASSIGN_OP
      case symbol_kind::S_ATTR_OP: // ATTR_OP
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
#line 53 "src/bison/parser.yy"
                                          { 
      root = new Node("Root", "", yylineno); 
      root->children.push_back(yystack_[2].value.as < Node * > ());
      root->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 862 "src/parser.tab.cc"
    break;

  case 3: // main_class: PUBLIC CLASS id LB PUBLIC STATIC VOID MAIN LP STRING LS RS id RP LB statement_list RB RB
#line 61 "src/bison/parser.yy"
                                                                                             {
    yylhs.value.as < Node * > () = new Node("main_class", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 873 "src/parser.tab.cc"
    break;

  case 4: // class_declaration_list: class_declaration
#line 70 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 879 "src/parser.tab.cc"
    break;

  case 5: // class_declaration_list: class_declaration_list class_declaration_list
#line 71 "src/bison/parser.yy"
                                                  {
    yylhs.value.as < Node * > () = new Node("class_decl_lst", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 889 "src/parser.tab.cc"
    break;

  case 6: // class_declaration: CLASS id LB class_content RB
#line 79 "src/bison/parser.yy"
                                 {
    yylhs.value.as < Node * > () = new Node("class_decl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 899 "src/parser.tab.cc"
    break;

  case 7: // class_content: var_declaration_list
#line 87 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 905 "src/parser.tab.cc"
    break;

  case 8: // class_content: method_declaration_list
#line 88 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 911 "src/parser.tab.cc"
    break;

  case 9: // class_content: class_content class_content
#line 89 "src/bison/parser.yy"
                                {
    yylhs.value.as < Node * > () = new Node("class_content", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 921 "src/parser.tab.cc"
    break;

  case 10: // var_declaration_list: var_declaration
#line 97 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 927 "src/parser.tab.cc"
    break;

  case 11: // var_declaration_list: var_declaration var_declaration_list
#line 98 "src/bison/parser.yy"
                                         {
    yylhs.value.as < Node * > () = new Node("var_decl_lst", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 937 "src/parser.tab.cc"
    break;

  case 12: // var_declaration: type id DELI
#line 106 "src/bison/parser.yy"
                 {
    yylhs.value.as < Node * > () = new Node("var_decl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 947 "src/parser.tab.cc"
    break;

  case 13: // method_declaration_list: method_declaration
#line 114 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 953 "src/parser.tab.cc"
    break;

  case 14: // method_declaration_list: method_declaration_list method_declaration_list
#line 115 "src/bison/parser.yy"
                                                    {
    yylhs.value.as < Node * > () = new Node("method_decl_lst", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 963 "src/parser.tab.cc"
    break;

  case 15: // method_declaration: method_head LP RP method_body
#line 123 "src/bison/parser.yy"
                                  {
    yylhs.value.as < Node * > () = new Node("method_decl", "declaration", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 973 "src/parser.tab.cc"
    break;

  case 16: // method_declaration: method_head LP method_arguments RP method_body
#line 128 "src/bison/parser.yy"
                                                   {
    yylhs.value.as < Node * > () = new Node("method_decl", "declaration", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 984 "src/parser.tab.cc"
    break;

  case 17: // method_head: PUBLIC type id
#line 137 "src/bison/parser.yy"
                   {
    yylhs.value.as < Node * > () = new Node("method_decl", "head", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 994 "src/parser.tab.cc"
    break;

  case 18: // method_body: LB RETURN expression_lst DELI RB
#line 145 "src/bison/parser.yy"
                                     {
    yylhs.value.as < Node * > () = new Node("method_decl", "body", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1003 "src/parser.tab.cc"
    break;

  case 19: // method_body: LB method_content RETURN expression_lst DELI RB
#line 149 "src/bison/parser.yy"
                                                    {
    yylhs.value.as < Node * > () = new Node("method_decl", "body", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1013 "src/parser.tab.cc"
    break;

  case 20: // method_arguments: type id
#line 157 "src/bison/parser.yy"
            {
    yylhs.value.as < Node * > () = new Node("method_arg", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1023 "src/parser.tab.cc"
    break;

  case 21: // method_arguments: method_arguments SEP method_arguments
#line 162 "src/bison/parser.yy"
                                          {
    yylhs.value.as < Node * > () = new Node("method_arg_lst", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1033 "src/parser.tab.cc"
    break;

  case 22: // method_content: var_declaration
#line 170 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1039 "src/parser.tab.cc"
    break;

  case 23: // method_content: statement
#line 171 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1045 "src/parser.tab.cc"
    break;

  case 24: // method_content: method_content method_content
#line 172 "src/bison/parser.yy"
                                  {
    yylhs.value.as < Node * > () = new Node("method_content", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1055 "src/parser.tab.cc"
    break;

  case 25: // type: INT LS RS
#line 180 "src/bison/parser.yy"
              { yylhs.value.as < Node * > () = new Node("type", "int_arr", yylineno); }
#line 1061 "src/parser.tab.cc"
    break;

  case 26: // type: BOOLEAN
#line 181 "src/bison/parser.yy"
            { yylhs.value.as < Node * > () = new Node("type", "boolean", yylineno); }
#line 1067 "src/parser.tab.cc"
    break;

  case 27: // type: INT
#line 182 "src/bison/parser.yy"
        { yylhs.value.as < Node * > () = new Node("type", "int", yylineno); }
#line 1073 "src/parser.tab.cc"
    break;

  case 28: // type: id
#line 183 "src/bison/parser.yy"
       { 
    yylhs.value.as < Node * > () = new Node("type", "id", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1082 "src/parser.tab.cc"
    break;

  case 29: // statement_list: statement
#line 190 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1088 "src/parser.tab.cc"
    break;

  case 30: // statement_list: statement_list statement_list
#line 191 "src/bison/parser.yy"
                                  {
    yylhs.value.as < Node * > () = new Node("statement_lst", "", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1098 "src/parser.tab.cc"
    break;

  case 31: // statement: LB statement_list RB
#line 199 "src/bison/parser.yy"
                         {
    yylhs.value.as < Node * > () = new Node("statement", "block", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1107 "src/parser.tab.cc"
    break;

  case 32: // statement: IF LP expression_lst RP statement
#line 203 "src/bison/parser.yy"
                                      {
    yylhs.value.as < Node * > () = new Node("statement", "if", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1117 "src/parser.tab.cc"
    break;

  case 33: // statement: IF LP expression_lst RP statement ELSE statement
#line 208 "src/bison/parser.yy"
                                                     {
    yylhs.value.as < Node * > () = new Node("statement", "if-else", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1128 "src/parser.tab.cc"
    break;

  case 34: // statement: WHILE LP expression_lst RP statement
#line 214 "src/bison/parser.yy"
                                         {
    yylhs.value.as < Node * > () = new Node("statement", "while", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1138 "src/parser.tab.cc"
    break;

  case 35: // statement: PRINT LP expression_lst RP DELI
#line 219 "src/bison/parser.yy"
                                    {
    yylhs.value.as < Node * > () = new Node("statement", "print", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1147 "src/parser.tab.cc"
    break;

  case 36: // statement: id ASSIGN_OP expression_lst DELI
#line 223 "src/bison/parser.yy"
                                     {
    yylhs.value.as < Node * > () = new Node("statement", "assign", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1157 "src/parser.tab.cc"
    break;

  case 37: // statement: id LS expression_lst RS ASSIGN_OP expression_lst DELI
#line 228 "src/bison/parser.yy"
                                                          {
    yylhs.value.as < Node * > () = new Node("statement", "assign_arr", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1168 "src/parser.tab.cc"
    break;

  case 38: // expression_lst: expression_lst SEP expression_lst
#line 237 "src/bison/parser.yy"
                                      {
    yylhs.value.as < Node * > () = new Node("expression_lst", "sep", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1178 "src/parser.tab.cc"
    break;

  case 39: // expression_lst: expression_lst operator expression_lst
#line 242 "src/bison/parser.yy"
                                           {
    yylhs.value.as < Node * > () = new Node("expression", "operator", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1189 "src/parser.tab.cc"
    break;

  case 40: // expression_lst: expression
#line 249 "src/bison/parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1195 "src/parser.tab.cc"
    break;

  case 41: // expression: expression LS expression_lst RS
#line 253 "src/bison/parser.yy"
                                    {
    yylhs.value.as < Node * > () = new Node("expression", "arr", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1205 "src/parser.tab.cc"
    break;

  case 42: // expression: expression ATTR_OP LENGTH
#line 258 "src/bison/parser.yy"
                              {
    yylhs.value.as < Node * > () = new Node("expression", "length", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1214 "src/parser.tab.cc"
    break;

  case 43: // expression: expression ATTR_OP id LP expression_lst RP
#line 262 "src/bison/parser.yy"
                                               {
    yylhs.value.as < Node * > () = new Node("expression", "attr_exp", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1225 "src/parser.tab.cc"
    break;

  case 44: // expression: expression ATTR_OP id LP RP
#line 268 "src/bison/parser.yy"
                                {
    yylhs.value.as < Node * > () = new Node("expression", "attr", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1235 "src/parser.tab.cc"
    break;

  case 45: // expression: LP expression_lst RP
#line 273 "src/bison/parser.yy"
                         {
    yylhs.value.as < Node * > () = new Node("expression", "brackets", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1244 "src/parser.tab.cc"
    break;

  case 46: // expression: NUMBER
#line 277 "src/bison/parser.yy"
           { yylhs.value.as < Node * > () = new Node("number", std::to_string(yystack_[0].value.as < int > ()),  yylineno); }
#line 1250 "src/parser.tab.cc"
    break;

  case 47: // expression: BOOL
#line 278 "src/bison/parser.yy"
         {
    std::string val;
    if (yystack_[0].value.as < bool > ()) {
      val = "true";
    } else {
      val = "false";
    }

    yylhs.value.as < Node * > () = new Node("bool", val, yylineno);
  }
#line 1265 "src/parser.tab.cc"
    break;

  case 48: // expression: id
#line 288 "src/bison/parser.yy"
       {
    yylhs.value.as < Node * > () = new Node("expression", "id", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1274 "src/parser.tab.cc"
    break;

  case 49: // expression: THIS
#line 292 "src/bison/parser.yy"
         {
    yylhs.value.as < Node * > () = new Node("expression", "this", yylineno);
  }
#line 1282 "src/parser.tab.cc"
    break;

  case 50: // expression: NEW INT LS expression_lst RS
#line 295 "src/bison/parser.yy"
                                 {
    yylhs.value.as < Node * > () = new Node("expression", "arr", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1291 "src/parser.tab.cc"
    break;

  case 51: // expression: NEW id LP RP
#line 299 "src/bison/parser.yy"
                 {
    yylhs.value.as < Node * > () = new Node("expression", "init", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1300 "src/parser.tab.cc"
    break;

  case 52: // expression: NOT_OP expression
#line 303 "src/bison/parser.yy"
                      {
    yylhs.value.as < Node * > () = new Node("expression", "not", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1309 "src/parser.tab.cc"
    break;

  case 53: // operator: ADD_OP
#line 310 "src/bison/parser.yy"
           { yylhs.value.as < Node * > () = new Node("operator", "add", yylineno); }
#line 1315 "src/parser.tab.cc"
    break;

  case 54: // operator: SUB_OP
#line 311 "src/bison/parser.yy"
           { yylhs.value.as < Node * > () = new Node("operator", "sub", yylineno); }
#line 1321 "src/parser.tab.cc"
    break;

  case 55: // operator: AND_OP
#line 312 "src/bison/parser.yy"
           { yylhs.value.as < Node * > () = new Node("operator", "and", yylineno); }
#line 1327 "src/parser.tab.cc"
    break;

  case 56: // operator: OR_OP
#line 313 "src/bison/parser.yy"
          { yylhs.value.as < Node * > () = new Node("operator", "or", yylineno); }
#line 1333 "src/parser.tab.cc"
    break;

  case 57: // operator: EQ_OP
#line 314 "src/bison/parser.yy"
          { yylhs.value.as < Node * > () = new Node("operator", "eq", yylineno); }
#line 1339 "src/parser.tab.cc"
    break;

  case 58: // operator: GT_OP
#line 315 "src/bison/parser.yy"
          { yylhs.value.as < Node * > () = new Node("operator", "gt", yylineno); }
#line 1345 "src/parser.tab.cc"
    break;

  case 59: // operator: LT_OP
#line 316 "src/bison/parser.yy"
          { yylhs.value.as < Node * > () = new Node("operator", "lt", yylineno); }
#line 1351 "src/parser.tab.cc"
    break;

  case 60: // operator: MULT_OP
#line 317 "src/bison/parser.yy"
            { yylhs.value.as < Node * > () = new Node("operator", "mult", yylineno); }
#line 1357 "src/parser.tab.cc"
    break;

  case 61: // id: ID
#line 321 "src/bison/parser.yy"
       {
    yylhs.value.as < Node * > () = new Node("id", yystack_[0].value.as < std::string > (),  yylineno);
  }
#line 1365 "src/parser.tab.cc"
    break;


#line 1369 "src/parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -51;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       3,   -11,    34,    27,    16,   -51,    16,    13,   -51,   -51,
      38,    42,   -51,    27,    35,    79,    39,   -51,    46,    37,
      45,   -51,    37,    48,   -51,    49,    16,   -51,    50,    54,
      16,   -51,    79,   -51,    48,    20,    55,    52,   -51,   -51,
      68,     7,    16,   -51,    77,   303,   -51,    37,    68,   -51,
      71,   326,   288,    80,    81,    87,   -51,   322,   -51,    -3,
      94,   -51,    75,   284,   -51,    -3,   288,    -5,   -51,   -51,
     -51,   288,   111,    -7,   -51,   288,   288,   288,   288,    98,
     288,   288,    89,   -51,   326,   121,    95,   101,    -7,   288,
     103,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   288,
     288,     0,   130,   164,   173,   152,   204,   195,    16,   -51,
     288,   110,   266,   -51,   266,   213,   -51,   113,   326,   326,
     107,   114,    91,   -51,   124,   244,   -51,   -51,    82,   -51,
     122,   -51,   -51,   288,   131,   -51,   -51,   253,   326,   235,
     326,   -51,   -51,   -51,   312,   123,   -51
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     1,     0,     0,     4,    61,
       0,     0,     2,     5,     0,     0,     0,    26,    27,     0,
       0,     7,    10,     8,    13,     0,     0,    28,     0,     0,
       0,     6,     9,    11,    14,     0,     0,     0,    25,    17,
       0,     0,     0,    12,     0,     0,    15,     0,     0,    20,
       0,     0,     0,     0,     0,     0,    22,     0,    23,    28,
      21,    16,     0,     0,    29,     0,     0,     0,    49,    46,
      47,     0,     0,    40,    48,     0,     0,     0,     0,    24,
       0,     0,     0,    31,    30,     0,     0,     0,    52,     0,
       0,    53,    54,    60,    57,    59,    58,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,    38,    18,    39,     0,    42,     0,     0,     0,
       0,     0,     0,    36,     0,     0,    51,    41,     0,    34,
      32,    35,    19,     0,     0,    50,    44,     0,     0,     0,
       0,    43,    33,    37,     0,     0,     3
  };

  const short
  parser::yypgoto_[] =
  {
     -51,   -51,   -51,   135,   -51,   151,   128,   -37,    -2,   -51,
     -51,   125,   129,   127,   -10,   -50,   -40,    -8,    99,   -51,
      -4
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     3,    13,     8,    32,    21,    22,    23,    24,
      25,    46,    41,    79,    26,    84,    64,    72,    73,    99,
      74
  };

  const unsigned char
  parser::yytable_[] =
  {
      10,    63,    11,   100,   116,    58,     4,    80,    56,    30,
      86,    27,    47,    12,    48,    27,    27,    58,    27,     1,
      56,    34,    36,    17,     9,    42,    39,    40,    27,     9,
       6,    27,    34,   101,     5,    18,    81,    42,    49,    58,
      17,    59,    56,    27,     6,     9,    14,    65,    17,     9,
      15,    16,    18,    59,    31,    35,    29,    28,    85,    65,
      18,    19,    37,    87,    19,    38,     9,   102,   103,   104,
     105,    44,   106,   107,     9,    59,    45,    43,   129,   130,
      65,   112,    17,    50,    62,    82,    75,    76,    66,   136,
     144,   114,   115,    77,    18,    19,    67,   117,   142,    47,
     108,    17,   125,    68,   124,   110,    51,   111,     9,    69,
      70,     9,   113,    18,    65,    65,    89,   126,    71,   128,
     137,    53,    54,   132,    55,   139,    89,     9,   109,   131,
     133,   134,   146,    90,    65,    89,    65,   118,     7,   140,
      65,    91,    92,    93,    94,    95,    96,   138,    97,    98,
      33,    91,    92,    93,    94,    95,    96,    89,    97,    98,
      91,    92,    93,    94,    95,    96,    20,    97,    98,    89,
      88,   119,    57,    61,   121,     0,    60,     0,    89,     0,
     120,     0,    91,    92,    93,    94,    95,    96,     0,    97,
      98,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      89,    97,    98,    91,    92,    93,    94,    95,    96,    89,
      97,    98,     0,     0,     0,   122,     0,   123,    89,     0,
       0,     0,     0,     0,   127,    91,    92,    93,    94,    95,
      96,     0,    97,    98,    91,    92,    93,    94,    95,    96,
      89,    97,    98,    91,    92,    93,    94,    95,    96,    89,
      97,    98,     0,     0,     0,   135,     0,   143,    89,     0,
     141,     0,     0,     0,     0,    91,    92,    93,    94,    95,
      96,    89,    97,    98,    91,    92,    93,    94,    95,    96,
       0,    97,    98,    91,    92,    93,    94,    95,    96,     0,
      97,    98,    51,    83,    66,     0,    91,    92,    93,    94,
      95,    96,    67,    97,    98,     0,    17,    53,    54,    68,
      55,    51,     0,     9,     0,    69,    70,     9,    18,     0,
      51,   145,     0,    52,    71,    17,    53,    54,     0,    55,
      51,     0,     9,     0,    51,    53,    54,    18,    55,     0,
       0,     9,    78,     0,     0,    53,    54,     0,    55,    53,
      54,     9,    55,     0,     0,     9
  };

  const short
  parser::yycheck_[] =
  {
       4,    51,     6,    10,     4,    45,    17,    10,    45,    19,
      15,    15,     5,     0,     7,    19,    20,    57,    22,    16,
      57,    23,    26,     3,    29,    35,    30,     7,    32,    29,
      17,    35,    34,    40,     0,    15,    39,    47,    42,    79,
       3,    45,    79,    47,    17,    29,     8,    51,     3,    29,
       8,    16,    15,    57,     9,     6,    10,    18,    66,    63,
      15,    16,    12,    67,    16,    11,    29,    75,    76,    77,
      78,    19,    80,    81,    29,    79,     8,    22,   118,   119,
      84,    89,     3,     6,    13,    10,     6,     6,     6,     7,
     140,    99,   100,     6,    15,    16,    14,   101,   138,     5,
      11,     3,   110,    21,   108,    10,     8,     6,    29,    27,
      28,    29,     9,    15,   118,   119,     5,     7,    36,     6,
     128,    23,    24,     9,    26,   133,     5,    29,     7,    22,
      39,     7,     9,    22,   138,     5,   140,     7,     3,     8,
     144,    30,    31,    32,    33,    34,    35,    25,    37,    38,
      22,    30,    31,    32,    33,    34,    35,     5,    37,    38,
      30,    31,    32,    33,    34,    35,    15,    37,    38,     5,
      71,     7,    45,    48,    22,    -1,    47,    -1,     5,    -1,
       7,    -1,    30,    31,    32,    33,    34,    35,    -1,    37,
      38,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
       5,    37,    38,    30,    31,    32,    33,    34,    35,     5,
      37,    38,    -1,    -1,    -1,    11,    -1,    22,     5,    -1,
      -1,    -1,    -1,    -1,    11,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    30,    31,    32,    33,    34,    35,
       5,    37,    38,    30,    31,    32,    33,    34,    35,     5,
      37,    38,    -1,    -1,    -1,    11,    -1,    22,     5,    -1,
       7,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,     5,    37,    38,    30,    31,    32,    33,    34,    35,
      -1,    37,    38,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,     8,     9,     6,    -1,    30,    31,    32,    33,
      34,    35,    14,    37,    38,    -1,     3,    23,    24,    21,
      26,     8,    -1,    29,    -1,    27,    28,    29,    15,    -1,
       8,     9,    -1,    20,    36,     3,    23,    24,    -1,    26,
       8,    -1,    29,    -1,     8,    23,    24,    15,    26,    -1,
      -1,    29,    20,    -1,    -1,    23,    24,    -1,    26,    23,
      24,    29,    26,    -1,    -1,    29
  };

  const signed char
  parser::yystos_[] =
  {
       0,    16,    42,    43,    17,     0,    17,    44,    45,    29,
      61,    61,     0,    44,     8,     8,    16,     3,    15,    16,
      46,    47,    48,    49,    50,    51,    55,    61,    18,    10,
      55,     9,    46,    47,    49,     6,    61,    12,    11,    61,
       7,    53,    55,    22,    19,     8,    52,     5,     7,    61,
       6,     8,    20,    23,    24,    26,    48,    54,    57,    61,
      53,    52,    13,    56,    57,    61,     6,    14,    21,    27,
      28,    36,    58,    59,    61,     6,     6,     6,    20,    54,
      10,    39,    10,     9,    56,    58,    15,    61,    59,     5,
      22,    30,    31,    32,    33,    34,    35,    37,    38,    60,
      10,    40,    58,    58,    58,    58,    58,    58,    11,     7,
      10,     6,    58,     9,    58,    58,     4,    61,     7,     7,
       7,    22,    11,    22,    61,    58,     7,    11,     6,    57,
      57,    22,     9,    39,     7,    11,     7,    58,    25,    58,
       8,     7,    57,    22,    56,     9,     9
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    43,    44,    44,    45,    46,    46,    46,
      47,    47,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    61
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,    18,     1,     2,     5,     1,     1,     2,
       1,     2,     3,     1,     2,     4,     5,     3,     5,     6,
       2,     3,     1,     1,     2,     3,     1,     1,     1,     1,
       2,     3,     5,     7,     5,     5,     4,     7,     3,     3,
       1,     4,     3,     6,     5,     3,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
  "SUB_OP", "MULT_OP", "EQ_OP", "LT_OP", "GT_OP", "NOT_OP", "AND_OP",
  "OR_OP", "ASSIGN_OP", "ATTR_OP", "$accept", "root", "main_class",
  "class_declaration_list", "class_declaration", "class_content",
  "var_declaration_list", "var_declaration", "method_declaration_list",
  "method_declaration", "method_head", "method_body", "method_arguments",
  "method_content", "type", "statement_list", "statement",
  "expression_lst", "expression", "operator", "id", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    53,    53,    61,    70,    71,    79,    87,    88,    89,
      97,    98,   106,   114,   115,   123,   128,   137,   145,   149,
     157,   162,   170,   171,   172,   180,   181,   182,   183,   190,
     191,   199,   203,   208,   214,   219,   223,   228,   237,   242,
     249,   253,   258,   262,   268,   273,   277,   278,   288,   292,
     295,   299,   303,   310,   311,   312,   313,   314,   315,   316,
     317,   321
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
#line 1967 "src/parser.tab.cc"

