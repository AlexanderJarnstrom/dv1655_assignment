// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 9 "parser.yy"

  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
  #define DEBUG true

#line 56 "parser.tab.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 191 "parser.tab.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // root
      // main_class
      // class_declaration_list
      // class_declaration
      // var_declaration_list
      // var_declaration
      // method_declaration_list
      // method_declaration
      // method_arguments
      // method_content
      // type
      // statement_list
      // statement_else
      // statement
      // expression
      // operator
      // number
      // bool
      // id
      char dummy1[sizeof (Node *)];

      // BOOL
      char dummy2[sizeof (bool)];

      // NUMBER
      char dummy3[sizeof (int)];

      // BOOLEAN
      // LENGTH
      // SEP
      // LP
      // RP
      // LB
      // RB
      // LS
      // RS
      // VOID
      // STRING
      // NEW
      // INT
      // PUBLIC
      // CLASS
      // STATIC
      // MAIN
      // RETURN
      // THIS
      // DELI
      // WHILE
      // IF
      // ELSE
      // PRINT
      // ID
      // ADD_OP
      // SUB_OP
      // MULT_OP
      // EQ_OP
      // LT_OP
      // GT_OP
      // NOT_OP
      // AND_OP
      // OR_OP
      // ASSIGN_OP
      // ATTR_OP
      char dummy4[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END = 0,                       // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    BOOLEAN = 258,                 // BOOLEAN
    LENGTH = 259,                  // LENGTH
    SEP = 260,                     // SEP
    LP = 261,                      // LP
    RP = 262,                      // RP
    LB = 263,                      // LB
    RB = 264,                      // RB
    LS = 265,                      // LS
    RS = 266,                      // RS
    VOID = 267,                    // VOID
    STRING = 268,                  // STRING
    NEW = 269,                     // NEW
    INT = 270,                     // INT
    PUBLIC = 271,                  // PUBLIC
    CLASS = 272,                   // CLASS
    STATIC = 273,                  // STATIC
    MAIN = 274,                    // MAIN
    RETURN = 275,                  // RETURN
    THIS = 276,                    // THIS
    DELI = 277,                    // DELI
    WHILE = 278,                   // WHILE
    IF = 279,                      // IF
    ELSE = 280,                    // ELSE
    PRINT = 281,                   // PRINT
    NUMBER = 282,                  // NUMBER
    BOOL = 283,                    // BOOL
    ID = 284,                      // ID
    ADD_OP = 285,                  // ADD_OP
    SUB_OP = 286,                  // SUB_OP
    MULT_OP = 287,                 // MULT_OP
    EQ_OP = 288,                   // EQ_OP
    LT_OP = 289,                   // LT_OP
    GT_OP = 290,                   // GT_OP
    NOT_OP = 291,                  // NOT_OP
    AND_OP = 292,                  // AND_OP
    OR_OP = 293,                   // OR_OP
    ASSIGN_OP = 294,               // ASSIGN_OP
    ATTR_OP = 295                  // ATTR_OP
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 41, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_BOOLEAN = 3,                           // BOOLEAN
        S_LENGTH = 4,                            // LENGTH
        S_SEP = 5,                               // SEP
        S_LP = 6,                                // LP
        S_RP = 7,                                // RP
        S_LB = 8,                                // LB
        S_RB = 9,                                // RB
        S_LS = 10,                               // LS
        S_RS = 11,                               // RS
        S_VOID = 12,                             // VOID
        S_STRING = 13,                           // STRING
        S_NEW = 14,                              // NEW
        S_INT = 15,                              // INT
        S_PUBLIC = 16,                           // PUBLIC
        S_CLASS = 17,                            // CLASS
        S_STATIC = 18,                           // STATIC
        S_MAIN = 19,                             // MAIN
        S_RETURN = 20,                           // RETURN
        S_THIS = 21,                             // THIS
        S_DELI = 22,                             // DELI
        S_WHILE = 23,                            // WHILE
        S_IF = 24,                               // IF
        S_ELSE = 25,                             // ELSE
        S_PRINT = 26,                            // PRINT
        S_NUMBER = 27,                           // NUMBER
        S_BOOL = 28,                             // BOOL
        S_ID = 29,                               // ID
        S_ADD_OP = 30,                           // ADD_OP
        S_SUB_OP = 31,                           // SUB_OP
        S_MULT_OP = 32,                          // MULT_OP
        S_EQ_OP = 33,                            // EQ_OP
        S_LT_OP = 34,                            // LT_OP
        S_GT_OP = 35,                            // GT_OP
        S_NOT_OP = 36,                           // NOT_OP
        S_AND_OP = 37,                           // AND_OP
        S_OR_OP = 38,                            // OR_OP
        S_ASSIGN_OP = 39,                        // ASSIGN_OP
        S_ATTR_OP = 40,                          // ATTR_OP
        S_YYACCEPT = 41,                         // $accept
        S_root = 42,                             // root
        S_main_class = 43,                       // main_class
        S_class_declaration_list = 44,           // class_declaration_list
        S_class_declaration = 45,                // class_declaration
        S_var_declaration_list = 46,             // var_declaration_list
        S_var_declaration = 47,                  // var_declaration
        S_method_declaration_list = 48,          // method_declaration_list
        S_method_declaration = 49,               // method_declaration
        S_method_arguments = 50,                 // method_arguments
        S_method_content = 51,                   // method_content
        S_type = 52,                             // type
        S_statement_list = 53,                   // statement_list
        S_statement_else = 54,                   // statement_else
        S_statement = 55,                        // statement
        S_expression = 56,                       // expression
        S_operator = 57,                         // operator
        S_number = 58,                           // number
        S_bool = 59,                             // bool
        S_id = 60                                // id
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
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
        value.move< Node * > (std::move (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< int > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Node *&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Node *& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
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
        value.template destroy< Node * > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.template destroy< int > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const bool& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const int& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
    parser ();
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END ()
      {
        return symbol_type (token::END);
      }
#else
      static
      symbol_type
      make_END ()
      {
        return symbol_type (token::END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN (std::string v)
      {
        return symbol_type (token::BOOLEAN, std::move (v));
      }
#else
      static
      symbol_type
      make_BOOLEAN (const std::string& v)
      {
        return symbol_type (token::BOOLEAN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LENGTH (std::string v)
      {
        return symbol_type (token::LENGTH, std::move (v));
      }
#else
      static
      symbol_type
      make_LENGTH (const std::string& v)
      {
        return symbol_type (token::LENGTH, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEP (std::string v)
      {
        return symbol_type (token::SEP, std::move (v));
      }
#else
      static
      symbol_type
      make_SEP (const std::string& v)
      {
        return symbol_type (token::SEP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LP (std::string v)
      {
        return symbol_type (token::LP, std::move (v));
      }
#else
      static
      symbol_type
      make_LP (const std::string& v)
      {
        return symbol_type (token::LP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RP (std::string v)
      {
        return symbol_type (token::RP, std::move (v));
      }
#else
      static
      symbol_type
      make_RP (const std::string& v)
      {
        return symbol_type (token::RP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LB (std::string v)
      {
        return symbol_type (token::LB, std::move (v));
      }
#else
      static
      symbol_type
      make_LB (const std::string& v)
      {
        return symbol_type (token::LB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RB (std::string v)
      {
        return symbol_type (token::RB, std::move (v));
      }
#else
      static
      symbol_type
      make_RB (const std::string& v)
      {
        return symbol_type (token::RB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LS (std::string v)
      {
        return symbol_type (token::LS, std::move (v));
      }
#else
      static
      symbol_type
      make_LS (const std::string& v)
      {
        return symbol_type (token::LS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RS (std::string v)
      {
        return symbol_type (token::RS, std::move (v));
      }
#else
      static
      symbol_type
      make_RS (const std::string& v)
      {
        return symbol_type (token::RS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (std::string v)
      {
        return symbol_type (token::VOID, std::move (v));
      }
#else
      static
      symbol_type
      make_VOID (const std::string& v)
      {
        return symbol_type (token::VOID, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v)
      {
        return symbol_type (token::STRING, std::move (v));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v)
      {
        return symbol_type (token::STRING, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW (std::string v)
      {
        return symbol_type (token::NEW, std::move (v));
      }
#else
      static
      symbol_type
      make_NEW (const std::string& v)
      {
        return symbol_type (token::NEW, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (std::string v)
      {
        return symbol_type (token::INT, std::move (v));
      }
#else
      static
      symbol_type
      make_INT (const std::string& v)
      {
        return symbol_type (token::INT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUBLIC (std::string v)
      {
        return symbol_type (token::PUBLIC, std::move (v));
      }
#else
      static
      symbol_type
      make_PUBLIC (const std::string& v)
      {
        return symbol_type (token::PUBLIC, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (std::string v)
      {
        return symbol_type (token::CLASS, std::move (v));
      }
#else
      static
      symbol_type
      make_CLASS (const std::string& v)
      {
        return symbol_type (token::CLASS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC (std::string v)
      {
        return symbol_type (token::STATIC, std::move (v));
      }
#else
      static
      symbol_type
      make_STATIC (const std::string& v)
      {
        return symbol_type (token::STATIC, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAIN (std::string v)
      {
        return symbol_type (token::MAIN, std::move (v));
      }
#else
      static
      symbol_type
      make_MAIN (const std::string& v)
      {
        return symbol_type (token::MAIN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (std::string v)
      {
        return symbol_type (token::RETURN, std::move (v));
      }
#else
      static
      symbol_type
      make_RETURN (const std::string& v)
      {
        return symbol_type (token::RETURN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THIS (std::string v)
      {
        return symbol_type (token::THIS, std::move (v));
      }
#else
      static
      symbol_type
      make_THIS (const std::string& v)
      {
        return symbol_type (token::THIS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DELI (std::string v)
      {
        return symbol_type (token::DELI, std::move (v));
      }
#else
      static
      symbol_type
      make_DELI (const std::string& v)
      {
        return symbol_type (token::DELI, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (std::string v)
      {
        return symbol_type (token::WHILE, std::move (v));
      }
#else
      static
      symbol_type
      make_WHILE (const std::string& v)
      {
        return symbol_type (token::WHILE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (std::string v)
      {
        return symbol_type (token::IF, std::move (v));
      }
#else
      static
      symbol_type
      make_IF (const std::string& v)
      {
        return symbol_type (token::IF, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v)
      {
        return symbol_type (token::ELSE, std::move (v));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v)
      {
        return symbol_type (token::ELSE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINT (std::string v)
      {
        return symbol_type (token::PRINT, std::move (v));
      }
#else
      static
      symbol_type
      make_PRINT (const std::string& v)
      {
        return symbol_type (token::PRINT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (int v)
      {
        return symbol_type (token::NUMBER, std::move (v));
      }
#else
      static
      symbol_type
      make_NUMBER (const int& v)
      {
        return symbol_type (token::NUMBER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (bool v)
      {
        return symbol_type (token::BOOL, std::move (v));
      }
#else
      static
      symbol_type
      make_BOOL (const bool& v)
      {
        return symbol_type (token::BOOL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v)
      {
        return symbol_type (token::ID, std::move (v));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v)
      {
        return symbol_type (token::ID, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD_OP (std::string v)
      {
        return symbol_type (token::ADD_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_ADD_OP (const std::string& v)
      {
        return symbol_type (token::ADD_OP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_OP (std::string v)
      {
        return symbol_type (token::SUB_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_SUB_OP (const std::string& v)
      {
        return symbol_type (token::SUB_OP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT_OP (std::string v)
      {
        return symbol_type (token::MULT_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_MULT_OP (const std::string& v)
      {
        return symbol_type (token::MULT_OP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ_OP (std::string v)
      {
        return symbol_type (token::EQ_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_EQ_OP (const std::string& v)
      {
        return symbol_type (token::EQ_OP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT_OP (std::string v)
      {
        return symbol_type (token::LT_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_LT_OP (const std::string& v)
      {
        return symbol_type (token::LT_OP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT_OP (std::string v)
      {
        return symbol_type (token::GT_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_GT_OP (const std::string& v)
      {
        return symbol_type (token::GT_OP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT_OP (std::string v)
      {
        return symbol_type (token::NOT_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_NOT_OP (const std::string& v)
      {
        return symbol_type (token::NOT_OP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_OP (std::string v)
      {
        return symbol_type (token::AND_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_AND_OP (const std::string& v)
      {
        return symbol_type (token::AND_OP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_OP (std::string v)
      {
        return symbol_type (token::OR_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_OR_OP (const std::string& v)
      {
        return symbol_type (token::OR_OP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_OP (std::string v)
      {
        return symbol_type (token::ASSIGN_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_ASSIGN_OP (const std::string& v)
      {
        return symbol_type (token::ASSIGN_OP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATTR_OP (std::string v)
      {
        return symbol_type (token::ATTR_OP, std::move (v));
      }
#else
      static
      symbol_type
      make_ATTR_OP (const std::string& v)
      {
        return symbol_type (token::ATTR_OP, v);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 310,     ///< Last index in yytable_.
      yynnts_ = 20,  ///< Number of nonterminal symbols.
      yyfinal_ = 5 ///< Termination state number.
    };



  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
    };
    // Last valid token kind.
    const int code_max = 295;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
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
        value.copy< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< int > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
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
        value.move< Node * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< int > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 2286 "parser.tab.hh"




#endif // !YY_YY_PARSER_TAB_HH_INCLUDED
