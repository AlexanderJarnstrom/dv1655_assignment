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





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 17 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;

#line 54 "parser.tab.cc"


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
#line 127 "parser.tab.cc"

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
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_arguments: // method_arguments
      case symbol_kind::S_method_content: // method_content
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement_else: // statement_else
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operator: // operator
      case symbol_kind::S_number: // number
      case symbol_kind::S_bool: // bool
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
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_arguments: // method_arguments
      case symbol_kind::S_method_content: // method_content
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement_else: // statement_else
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operator: // operator
      case symbol_kind::S_number: // number
      case symbol_kind::S_bool: // bool
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
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_arguments: // method_arguments
      case symbol_kind::S_method_content: // method_content
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement_else: // statement_else
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operator: // operator
      case symbol_kind::S_number: // number
      case symbol_kind::S_bool: // bool
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
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_arguments: // method_arguments
      case symbol_kind::S_method_content: // method_content
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement_else: // statement_else
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operator: // operator
      case symbol_kind::S_number: // number
      case symbol_kind::S_bool: // bool
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
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_arguments: // method_arguments
      case symbol_kind::S_method_content: // method_content
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement_else: // statement_else
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operator: // operator
      case symbol_kind::S_number: // number
      case symbol_kind::S_bool: // bool
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
#line 52 "parser.yy"
                                          { 
      root = new Node("Root", "", yylineno); 
      root->children.push_back(yystack_[2].value.as < Node * > ());
      root->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 857 "parser.tab.cc"
    break;

  case 3: // main_class: PUBLIC CLASS id LB PUBLIC STATIC VOID MAIN LP STRING LS RS id RP LB statement_list RB RB
#line 60 "parser.yy"
                                                                                             {
    yylhs.value.as < Node * > () = new Node("Main Class", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 868 "parser.tab.cc"
    break;

  case 4: // class_declaration_list: class_declaration class_declaration_list
#line 69 "parser.yy"
                                             {
    yylhs.value.as < Node * > () = new Node("Class Declaration List", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 878 "parser.tab.cc"
    break;

  case 5: // class_declaration_list: %empty
#line 74 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("", "", yylineno); }
#line 884 "parser.tab.cc"
    break;

  case 6: // class_declaration: CLASS id LB var_declaration_list method_declaration_list RB
#line 77 "parser.yy"
                                                                {
    yylhs.value.as < Node * > () = new Node("Class Declaration", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 895 "parser.tab.cc"
    break;

  case 7: // var_declaration_list: var_declaration var_declaration_list
#line 86 "parser.yy"
                                         {
    yylhs.value.as < Node * > () = new Node("Variable Declaration List", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 905 "parser.tab.cc"
    break;

  case 8: // var_declaration_list: %empty
#line 91 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("", "", yylineno); }
#line 911 "parser.tab.cc"
    break;

  case 9: // var_declaration: type id DELI
#line 95 "parser.yy"
                 {
    yylhs.value.as < Node * > () = new Node("Variable Declaration", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 921 "parser.tab.cc"
    break;

  case 10: // method_declaration_list: method_declaration method_declaration_list
#line 103 "parser.yy"
                                               {
    yylhs.value.as < Node * > () = new Node("Method Declaration List", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 931 "parser.tab.cc"
    break;

  case 11: // method_declaration_list: %empty
#line 108 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("", "", yylineno); }
#line 937 "parser.tab.cc"
    break;

  case 12: // method_declaration: PUBLIC type id LP method_arguments RP LB method_content RETURN expression DELI RB
#line 112 "parser.yy"
                                                                                      {
    yylhs.value.as < Node * > () = new Node("Method", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 950 "parser.tab.cc"
    break;

  case 13: // method_arguments: type id
#line 123 "parser.yy"
            {
    yylhs.value.as < Node * > () = new Node("Method Argument", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 960 "parser.tab.cc"
    break;

  case 14: // method_arguments: method_arguments SEP method_arguments
#line 128 "parser.yy"
                                          {
    yylhs.value.as < Node * > () = new Node("Method Arguments", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 970 "parser.tab.cc"
    break;

  case 15: // method_arguments: %empty
#line 133 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("", "", yylineno); }
#line 976 "parser.tab.cc"
    break;

  case 16: // method_content: var_declaration method_content
#line 137 "parser.yy"
                                   {
    yylhs.value.as < Node * > () = new Node("Method Content", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 986 "parser.tab.cc"
    break;

  case 17: // method_content: statement method_content
#line 142 "parser.yy"
                             {
    yylhs.value.as < Node * > () = new Node("Method Content", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 996 "parser.tab.cc"
    break;

  case 18: // method_content: %empty
#line 147 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("", "", yylineno); }
#line 1002 "parser.tab.cc"
    break;

  case 19: // type: INT LS RS
#line 151 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Type", "Int arr", yylineno); }
#line 1008 "parser.tab.cc"
    break;

  case 20: // type: BOOLEAN
#line 152 "parser.yy"
            { yylhs.value.as < Node * > () = new Node("Type", "Boolean", yylineno); }
#line 1014 "parser.tab.cc"
    break;

  case 21: // type: INT
#line 153 "parser.yy"
        { yylhs.value.as < Node * > () = new Node("Type", "Int", yylineno); }
#line 1020 "parser.tab.cc"
    break;

  case 22: // type: id
#line 154 "parser.yy"
       { 
    yylhs.value.as < Node * > () = new Node("Type", "", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1029 "parser.tab.cc"
    break;

  case 23: // statement_list: statement statement_list
#line 161 "parser.yy"
                             {
    yylhs.value.as < Node * > () = new Node("Statement List", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1039 "parser.tab.cc"
    break;

  case 24: // statement_list: %empty
#line 166 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("", "", yylineno); }
#line 1045 "parser.tab.cc"
    break;

  case 25: // statement_else: ELSE statement
#line 170 "parser.yy"
                   {
    yylhs.value.as < Node * > () = new Node("Else statement", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1054 "parser.tab.cc"
    break;

  case 26: // statement_else: %empty
#line 174 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("", "", yylineno); }
#line 1060 "parser.tab.cc"
    break;

  case 27: // statement: LB statement_list RB
#line 178 "parser.yy"
                         {
    yylhs.value.as < Node * > () = new Node("Statement", "", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1069 "parser.tab.cc"
    break;

  case 28: // statement: IF LP expression RP statement statement_else
#line 182 "parser.yy"
                                                 {
    yylhs.value.as < Node * > () = new Node("IF Statement", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1080 "parser.tab.cc"
    break;

  case 29: // statement: WHILE LP expression RP statement
#line 188 "parser.yy"
                                     {
    yylhs.value.as < Node * > () = new Node("While Statement", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1090 "parser.tab.cc"
    break;

  case 30: // statement: PRINT LP expression RP DELI
#line 193 "parser.yy"
                                {
    yylhs.value.as < Node * > () = new Node("Print Statement", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1099 "parser.tab.cc"
    break;

  case 31: // statement: id ASSIGN_OP expression DELI
#line 197 "parser.yy"
                                 {
    yylhs.value.as < Node * > () = new Node("Assign Statement", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1109 "parser.tab.cc"
    break;

  case 32: // statement: id LS expression RS ASSIGN_OP expression DELI
#line 202 "parser.yy"
                                                  {
    yylhs.value.as < Node * > () = new Node("Assign Arr Statement", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1120 "parser.tab.cc"
    break;

  case 33: // expression: expression operator expression
#line 211 "parser.yy"
                                   {
    yylhs.value.as < Node * > () = new Node("Operator Expression", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1131 "parser.tab.cc"
    break;

  case 34: // expression: expression SEP expression
#line 217 "parser.yy"
                              {
    yylhs.value.as < Node * > () = new Node("Expression List", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1141 "parser.tab.cc"
    break;

  case 35: // expression: expression LS expression RS
#line 222 "parser.yy"
                                {
    yylhs.value.as < Node * > () = new Node("Array Expression", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1151 "parser.tab.cc"
    break;

  case 36: // expression: expression ATTR_OP LENGTH
#line 227 "parser.yy"
                              {
    yylhs.value.as < Node * > () = new Node("Expression Length", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1160 "parser.tab.cc"
    break;

  case 37: // expression: expression ATTR_OP id LP expression RP
#line 231 "parser.yy"
                                           {
    yylhs.value.as < Node * > () = new Node("Expression Attr", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1171 "parser.tab.cc"
    break;

  case 38: // expression: number
#line 237 "parser.yy"
           {
    yylhs.value.as < Node * > () = new Node("Expression Number", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1180 "parser.tab.cc"
    break;

  case 39: // expression: bool
#line 241 "parser.yy"
         {
    yylhs.value.as < Node * > () = new Node("Expression Bool", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1189 "parser.tab.cc"
    break;

  case 40: // expression: id
#line 245 "parser.yy"
       {
    yylhs.value.as < Node * > () = new Node("Expression ID", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1198 "parser.tab.cc"
    break;

  case 41: // expression: THIS
#line 249 "parser.yy"
         {
    yylhs.value.as < Node * > () = new Node("This", "", yylineno);
  }
#line 1206 "parser.tab.cc"
    break;

  case 42: // expression: NEW INT LS expression RS
#line 252 "parser.yy"
                             {
    yylhs.value.as < Node * > () = new Node("Expression Array", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1215 "parser.tab.cc"
    break;

  case 43: // expression: NEW id LP RP
#line 256 "parser.yy"
                 {
    yylhs.value.as < Node * > () = new Node("Init", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1224 "parser.tab.cc"
    break;

  case 44: // expression: NOT_OP expression
#line 260 "parser.yy"
                      {
    yylhs.value.as < Node * > () = new Node("Neg Expression", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1233 "parser.tab.cc"
    break;

  case 45: // expression: LP expression RP
#line 264 "parser.yy"
                     {
    yylhs.value.as < Node * > () = new Node("()", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1242 "parser.tab.cc"
    break;

  case 46: // expression: %empty
#line 268 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("", "", yylineno); }
#line 1248 "parser.tab.cc"
    break;

  case 47: // operator: ADD_OP
#line 272 "parser.yy"
           { yylhs.value.as < Node * > () = new Node("Operator", yystack_[0].value.as < std::string > (), yylineno); }
#line 1254 "parser.tab.cc"
    break;

  case 48: // operator: SUB_OP
#line 273 "parser.yy"
           { yylhs.value.as < Node * > () = new Node("Operator", yystack_[0].value.as < std::string > (), yylineno); }
#line 1260 "parser.tab.cc"
    break;

  case 49: // operator: EQ_OP
#line 274 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Operator", yystack_[0].value.as < std::string > (), yylineno); }
#line 1266 "parser.tab.cc"
    break;

  case 50: // operator: GT_OP
#line 275 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Operator", yystack_[0].value.as < std::string > (), yylineno); }
#line 1272 "parser.tab.cc"
    break;

  case 51: // operator: LT_OP
#line 276 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Operator", yystack_[0].value.as < std::string > (), yylineno); }
#line 1278 "parser.tab.cc"
    break;

  case 52: // operator: MULT_OP
#line 277 "parser.yy"
            { yylhs.value.as < Node * > () = new Node("Operator", yystack_[0].value.as < std::string > (), yylineno); }
#line 1284 "parser.tab.cc"
    break;

  case 53: // number: NUMBER
#line 281 "parser.yy"
           { yylhs.value.as < Node * > () = new Node("Number", std::to_string(yystack_[0].value.as < int > ()),  yylineno); }
#line 1290 "parser.tab.cc"
    break;

  case 54: // bool: BOOL
#line 285 "parser.yy"
         { 
    std::string val;
    if (yystack_[0].value.as < bool > ()) {
      val = "true";
    } else {
      val = "false";
    }

    yylhs.value.as < Node * > () = new Node("Bool", val,  yylineno);
  }
#line 1305 "parser.tab.cc"
    break;

  case 55: // id: ID
#line 298 "parser.yy"
       { yylhs.value.as < Node * > () = new Node("Id", yystack_[0].value.as < std::string > (),  yylineno); }
#line 1311 "parser.tab.cc"
    break;


#line 1315 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -52;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -11,    20,     6,    24,     3,   -52,     3,    46,    24,   -52,
      48,    52,   -52,   -52,    45,     0,    50,   -52,    59,    57,
       0,     3,   -52,    54,    64,     0,    67,    57,   -52,    65,
      61,   -52,     3,   -52,   -52,   -52,    72,    80,    75,     0,
      84,    58,     3,    79,     0,    92,   -52,     3,    91,    10,
      95,   118,    97,   101,   104,    10,    85,    10,    -9,   103,
     105,   118,    -9,    56,    56,    56,   -52,    56,   -52,    56,
      56,   118,   -52,   -52,    56,    -6,   -52,   -52,   -52,    56,
      88,   -52,   -52,   -52,    99,   130,   144,   162,   176,   106,
     194,   102,   110,     2,    56,   118,    56,   -52,   -52,   -52,
     -52,   -52,   -52,    15,    56,   118,   114,   108,   107,   -52,
     115,   -52,    56,   120,   270,   -52,   207,   -52,   132,   270,
     123,   -52,   -52,    56,   -52,   225,   -52,   -52,    56,   118,
     -52,   239,   -52,   257,   -52,   -52,   -52
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     5,     0,     1,     0,     0,     5,    55,
       0,     0,     2,     4,     0,     8,     0,    20,    21,    11,
       8,     0,    22,     0,     0,     0,     0,    11,     7,     0,
       0,    19,     0,     6,    10,     9,     0,     0,     0,    15,
       0,     0,     0,     0,    15,     0,    13,     0,    14,    18,
       0,    24,     0,     0,     0,    18,     0,    18,    22,     0,
       0,    24,     0,    46,    46,    46,    16,    46,    17,    46,
      46,    24,    27,    23,    46,     0,    41,    53,    54,    46,
       0,    38,    39,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    46,     0,    46,    47,    48,    52,
      49,    51,    50,     0,    46,     0,     0,     0,     0,    31,
       0,    45,    46,     0,    34,    29,     0,    36,     0,    33,
      26,    30,    12,    46,     3,     0,    43,    35,    46,     0,
      28,     0,    42,     0,    25,    32,    37
  };

  const short
  parser::yypgoto_[] =
  {
     -52,   -52,   -52,   135,   -52,   125,    11,   124,   -52,   109,
      17,   -17,   -51,   -52,   -47,   -15,   -52,   -52,   -52,    -4
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     7,     8,    19,    55,    26,    27,    41,
      56,    21,    60,   130,    57,    80,   104,    81,    82,    83
  };

  const unsigned char
  parser::yytable_[] =
  {
      10,    69,    11,    17,    61,     1,     5,    94,    32,    91,
      73,    22,    96,    17,    61,    18,    22,    29,    51,   117,
      89,    22,    42,     9,    61,    18,    20,    42,    37,     9,
      70,    20,     9,    52,    53,    22,    54,     4,    46,     9,
      22,     6,   103,    50,     9,    58,    12,    62,   115,    84,
      85,    58,    86,    58,    87,    88,    14,    62,   120,    90,
      15,    16,    74,    44,    93,    45,    30,    62,    23,    24,
      75,    92,    66,    25,    68,    31,    33,    76,    38,   114,
      36,   116,   134,    77,    78,     9,    39,    35,    40,   119,
      47,    62,    79,    94,    43,    95,    44,   125,    96,   118,
      49,    62,    59,    63,    94,    67,   105,    64,   131,    96,
      65,    71,   112,   133,    72,   110,   113,   122,    97,    98,
      99,   100,   101,   102,   124,    62,    51,   126,   103,    97,
      98,    99,   100,   101,   102,    94,   121,   106,   128,   103,
      96,    52,    53,    13,    54,    28,   123,     9,   129,    94,
       0,    34,     0,    48,    96,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   107,    94,     0,     0,
     103,     0,    96,   108,    97,    98,    99,   100,   101,   102,
       0,    94,     0,     0,   103,     0,    96,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   109,    94,
       0,   111,   103,     0,    96,     0,    97,    98,    99,   100,
     101,   102,    94,     0,     0,     0,   103,    96,   127,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
      94,     0,     0,     0,   103,    96,   132,    97,    98,    99,
     100,   101,   102,     0,    94,     0,     0,   103,     0,    96,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   135,    94,     0,   136,   103,     0,    96,     0,    97,
      98,    99,   100,   101,   102,    94,     0,     0,     0,   103,
      96,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,     0,     0,     0,     0,   103,     0,     0,
      97,    98,    99,   100,   101,   102,     0,     0,     0,     0,
     103
  };

  const short
  parser::yycheck_[] =
  {
       4,    10,     6,     3,    51,    16,     0,     5,    25,    15,
      61,    15,    10,     3,    61,    15,    20,    21,     8,     4,
      71,    25,    39,    29,    71,    15,    15,    44,    32,    29,
      39,    20,    29,    23,    24,    39,    26,    17,    42,    29,
      44,    17,    40,    47,    29,    49,     0,    51,    95,    64,
      65,    55,    67,    57,    69,    70,     8,    61,   105,    74,
       8,    16,     6,     5,    79,     7,    12,    71,    18,    10,
      14,    75,    55,    16,    57,    11,     9,    21,     6,    94,
      19,    96,   129,    27,    28,    29,     6,    22,    13,   104,
      11,    95,    36,     5,    10,     7,     5,   112,    10,   103,
       8,   105,     7,     6,     5,    20,     7,     6,   123,    10,
       6,     8,    10,   128,     9,     9,     6,     9,    30,    31,
      32,    33,    34,    35,     9,   129,     8,     7,    40,    30,
      31,    32,    33,    34,    35,     5,    22,     7,     6,    40,
      10,    23,    24,     8,    26,    20,    39,    29,    25,     5,
      -1,    27,    -1,    44,    10,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    22,     5,    -1,    -1,
      40,    -1,    10,    11,    30,    31,    32,    33,    34,    35,
      -1,     5,    -1,    -1,    40,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    22,     5,
      -1,     7,    40,    -1,    10,    -1,    30,    31,    32,    33,
      34,    35,     5,    -1,    -1,    -1,    40,    10,    11,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
       5,    -1,    -1,    -1,    40,    10,    11,    30,    31,    32,
      33,    34,    35,    -1,     5,    -1,    -1,    40,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    22,     5,    -1,     7,    40,    -1,    10,    -1,    30,
      31,    32,    33,    34,    35,     5,    -1,    -1,    -1,    40,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40
  };

  const signed char
  parser::yystos_[] =
  {
       0,    16,    42,    43,    17,     0,    17,    44,    45,    29,
      60,    60,     0,    44,     8,     8,    16,     3,    15,    46,
      47,    52,    60,    18,    10,    16,    48,    49,    46,    60,
      12,    11,    52,     9,    48,    22,    19,    60,     6,     6,
      13,    50,    52,    10,     5,     7,    60,    11,    50,     8,
      60,     8,    23,    24,    26,    47,    51,    55,    60,     7,
      53,    55,    60,     6,     6,     6,    51,    20,    51,    10,
      39,     8,     9,    53,     6,    14,    21,    27,    28,    36,
      56,    58,    59,    60,    56,    56,    56,    56,    56,    53,
      56,    15,    60,    56,     5,     7,    10,    30,    31,    32,
      33,    34,    35,    40,    57,     7,     7,    22,    11,    22,
       9,     7,    10,     6,    56,    55,    56,     4,    60,    56,
      55,    22,     9,    39,     9,    56,     7,    11,     6,    25,
      54,    56,    11,    56,    55,    22,     7
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    43,    44,    44,    45,    46,    46,    47,
      48,    48,    49,    50,    50,    50,    51,    51,    51,    52,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      57,    57,    57,    58,    59,    60
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,    18,     2,     0,     6,     2,     0,     3,
       2,     0,    12,     2,     3,     0,     2,     2,     0,     3,
       1,     1,     1,     2,     0,     2,     0,     3,     6,     5,
       5,     4,     7,     3,     3,     4,     3,     6,     1,     1,
       1,     1,     5,     4,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  "class_declaration_list", "class_declaration", "var_declaration_list",
  "var_declaration", "method_declaration_list", "method_declaration",
  "method_arguments", "method_content", "type", "statement_list",
  "statement_else", "statement", "expression", "operator", "number",
  "bool", "id", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    52,    52,    60,    69,    74,    77,    86,    91,    95,
     103,   108,   112,   123,   128,   133,   137,   142,   147,   151,
     152,   153,   154,   161,   166,   170,   174,   178,   182,   188,
     193,   197,   202,   211,   217,   222,   227,   231,   237,   241,
     245,   249,   252,   256,   260,   264,   268,   272,   273,   274,
     275,   276,   277,   281,   285,   298
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
#line 1897 "parser.tab.cc"

