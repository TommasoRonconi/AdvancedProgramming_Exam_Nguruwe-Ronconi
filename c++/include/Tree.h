/**
 *  @file include/Tree.h
 *
 *  @brief The class Tree
 *
 *  This file defines the interface of the class Tree
 *
 *  @author Herbert Nguruwe, Tommaso Ronconi
 *
 *  @author hknguruwe@gmail.com, tronconi@sissa.it
 */


#ifndef __TREE__
#define __TREE__
#include <iostream>
#include <memory>
#include <BST_utility.h>
#include <Node.h>
#include <Iterator.h>


/**
 *  @class Tree Tree.h "include/Tree.h"
 *
 *  @brief The class Tree
 *
 *  This class is used to handle objects of type <EM> Tree
 *  </EM>. It is templated on two types T and U for the  
 *  <EM> key </EM> and <EM> value </EM> of the tree, respectively.
 */
template < class T, class U >
class Tree {

  using Node = struct Node< T, U >;
  
  /**
   *  @name Custom-types owned by the class Tree
   */
  ///@{

  // /**
  //  *  @class Node Tree.h "include/Tree.h"
  //  *
  //  *  @brief The class Node
  //  *
  //  *  This custom-type is used to handle objects of type <EM> Node
  //  *  </EM>. It is templated on two types T and U for the  
  //  *  <EM> key </EM> and <EM> value </EM> of the tree, respectively.
  //  *  The templated scheme is deduced from the owner class Tree.
  //  */
  // struct Node;

  ///@}


  /**
   *  @name Private variables of the class
   */
  ///@{

  /// The root node of the BST
  std::unique_ptr<Node> root = nullptr;

  /// The head of the BST
  std::unique_ptr<Node> head = nullptr;

  /// The tail of the BST
  std::unique_ptr<Node> tail = nullptr;

  ///@}
  
public:
  using Iterator = class Iterator< T, U >;
  using ConstIterator = class ConstIterator< T, U >;

  /**
   *  @name Friends of the class Tree
   */
  ///@{

  /// operator<< overload
  template < class ot, class ou >
    friend std::ostream& operator<< ( std::ostream&, const Tree< ot, ou >& );

  /// operator[] overload, constant version
  // template < class ot, class ou >
  //   ou& operator[] ( const ot& key ) const;

  // /// operator[] overload, non-constant version
  // template < class ot, class ou >
  //   ou& operator[] ( const ot& key );

  ///@}

  /**
   *  @name Constructors/Destructor
   */
  ///@{


  /// default constructor
  Tree() = default;
  // Tree () { std::cout << "default ctor\n"; }

  /// copy-constructor
  Tree( const Tree & t );

  /// copy-assignment overload
  Tree& operator= (const Tree& t);

  
  /// move ctor
  Tree(Tree&& t) noexcept
    : root{std::move(t.root)},
      head{std::move(t.head)},
      tail{std::move(t.tail)} {}

  /// move assignment
  Tree& operator=(Tree&& t) noexcept  {
    
    root = std::move(t.root);
    head = std::move(t.head);
    tail = std::move(t.tail);
    
    return *this;
  }
  
  ~Tree() noexcept = default;
  // ~Tree() noexcept { std::cout << "default dtor\n"; };

  ///@}

  /**
   *  @name Iterators declaration
   */
  ///@{

  // class Iterator;
  // class ConstIterator;
  Iterator begin() { return Iterator{ head.get() }; }
  Iterator end() { return Iterator{ tail.get() }; }
  Iterator top() { return Iterator{ root.get() }; }

  ConstIterator cbegin() const { return ConstIterator{ head.get() }; }
  ConstIterator cend() const { return ConstIterator{ tail.get() }; }
  ConstIterator ctop() const { return ConstIterator{ root.get() }; }

  ///@}

  /**
   *  @name Public functions of the class Tree
   */
  ///@{


  void insert ( const T key, const U value, const bool substitute ) {

    if ( root ) root->insert( key, value, substitute );

    else root.reset( new Node{ key, value } );

  }

  void clear ();

  void balance ();

  ConstIterator find ( const T key );

  ///@}
  
  
}; // end of class Tree

template < class ot, class ou >
  std::ostream& operator<< (std::ostream& os, const Tree< ot, ou >& t) {

  if ( t.top() )
    return ( os << t.end() );
  else
    return ( os << " Empty tree " );
}

// ===========================================================================


#endif //__TREE__
