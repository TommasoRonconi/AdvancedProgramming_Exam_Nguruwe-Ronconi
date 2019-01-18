#ifndef __NODE__
#define __NODE__

#include <memory>
#include <utility>
#include <BST_utility.h>

template< class T, class U >
struct Node {

  /// Content of the node
  std::pair< T, U > content;
    
  /// Pointer to parent Node
  Node * parent = nullptr;

  /// Pointer to left Node
  std::unique_ptr<Node> left = nullptr;

  /// Pointer to right Node
  std::unique_ptr<Node> right = nullptr;

  /**
   *  @name Constructors/Destructor
   */
  ///@{

  /// default constructor
  Node () : content{ std::pair<T, U>{} }, parent{ nullptr } {}

  /// constructor that takes a key and a value as the input
  Node ( T key, U value )
    : content{ std::pair<T,U>( key, value ) } {}
  /* Node(const T& v, Node* n) : val{v}, next{n} {} */

  // ==================== copy/move ===================
  // /// copy-constructor
  // Node( const Node & n ) : content{ n.content } {}

  // /// copy-assignment overload ( just copies the content of node into a new Node with left, right, parent all pointing to nullptr )
   Node& operator= ( const Node& n ) {
     std::cout<< "copying";
     auto tmp = n;
     (*this) = std::move(tmp);
     std::cout << " )\n";
     return *this;
    //return Node{ n.key(), n.value() };
    
   }

  /// move-constructor
  // Node( Node && n ) noexcept
  //   : content{std::move(n.content)},
  //     parent{std::move(n.parent)},
  //     left{std::move(n.left)},
  //     right{std::move(n.right)} {}

  // /// move assignment
  // Node& operator=(Node&& n) noexcept  {

  //   content = std::move(n.content);
  //   parent = std::move(n.parent);
  //   left = std::move(n.left);
  //   right = std::move(n.right);
    
  //   return *this;
    
  // }
  // ==================================================
  

  ~Node() = default;

  /// operator<< overload
  template < class ot, class ou >
    friend std::ostream& operator<< ( std::ostream&, const Node< ot, ou >& n );

  ///@}

  /**
   *  @name Public functions of the struct Node
   */
  ///@{

  T key() { return content.first; }

  U value() { return content.second; }


  /**
   *  @brief get the pointer corresponding to bst::direction
   *  
   *  @param dir the direction to take
   *
   *  @return pointer to child in the given direction
   */
  std::unique_ptr<Node> get_direction ( bst::direction dir ) {
      
    if ( dir == bst::direction::left ) return std::move( left );
    else return std::move( right );
      
  }    


  /**
   *  @brief 
   *
   *  @param insert reference to unique_ptr to Node
   *  
   *  @param k for key, v for value and sub boolean to replace key if exists
   *
   *  @return  void
   */
    void insert (int k, int v, bool sub) {
      
      if ( k == content.first && sub ) content.second = v;
      
      if( k < content.first ) {
        if( left ) {
	  
          left->insert( k, v, sub );
          left.reset( new Node { k, v, this } );
	  
        }

      if ( k < content.first ) {
        if ( right ) {
	  
          right->insert( k, v, sub );
          right.reset( new Node{ k, v, parent } );
	  
        }
    
    }


  ///@}
    
}; // end of class Node


template < class T, class U >
  std::ostream& operator<< (std::ostream& os, const Node< T,U >& n) {

  if ( n.parent ) {
    os << n.key() << ":\t" << n.value() << "\n";
    return ( os << *( n.parent ) );
  }
  
  return ( os << n.key() << ":\t" << n.value() );
  
}

#endif //__NODE__
