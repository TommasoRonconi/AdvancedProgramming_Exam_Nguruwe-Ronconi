#include <Tree.h>
#include <memory>

int main( /* int argc, char * argv[] */ ) {

  // ================================================================================================
  // =========================================== test Node ==========================================
  // ================================================================================================
  // Working tests:
  // Node< int, double > N { 4, 5.1 };
  // std::cout << N.key() << "  " << N.value() << std::endl;
  // N.insert( 3, 6.2, true );
  // std::cout << N.left->key() << "  " << N.left->value() << std::endl;
  // std::cout << N.left->parent->key() << "  " << N.left->parent->value() << std::endl;
  // N.left->insert( 2, 7.3, true );
  // std::cout << N.left->right->key() << "  " << N.left->right->value() << std::endl;
  // std::cout << N.left->right->parent->key() << "  " << N.left->right->parent->value() << std::endl;
  // ================================================================================================
  // Still not working (probably copy constructor needed (or kindof))
  // std::cout << N.leftmost()->key() << "  " << N.leftmost()->value() << std::endl;
  // Node< int, double > * N2 = N.leftmost();
  // std::cout << N2->key() << "  " << N2->value() << std::endl;
  // ================================================================================================
  
  Tree< int, double > T {};
  int key = 4;
  double value = 5.1;
  bool sub = true;
  T.insert( key, value, sub );

  // Node< int, double> N1 { 4, 2.5 };
  // std::cout << N1.key() << "  " << N1.value() << std::endl;
  // if ( N1.left )
  //   std::cout << "not null\n";
  // else
  //   std::cout << "null\n";

  // Node< int, double > NL { 3, 4.6 };
  // N1.left = std::make_unique< Node< int, double > >(  3, 4.6  );

  // auto N3 = N1.get_direction( bst::direction::left );
  // std::cout << N3->key() << "  " << N3->value() << std::endl;

  // std::unique_ptr< Node< int, double > > N4 { new Node< int, double > { 5, 5.1 } };
  // N1.new_node( N4, bst::direction::right );
  // if ( N1.right ) 
  //   std::cout << N1.right->key() << "  " << N1.right->value() << std::endl;
  // auto N5 = std::make_unique< Node< int, double > >(  N1  );
  

  // ============================================================
  // std::pair< int, double > p1 {2, 4.};
  // auto p2 { p1 };
  // std::cout << p1.first << "  " << p2.first << std::endl;
  // std::cout << p1.second << "  " << p2.second << std::endl;
  // ============================================================

  // Tree< int, double >::Node N1;
  // if ( N1->parent )
  //   std::cout << "Blabla\n";

  
  // Tree< int, double > T1;
  // std::cout << *(T1.begin()) << std::endl;
  // auto it = T1.begin();
  // if (!it->)
  //   std::cout << "nullptr!\n";
  
  /* code */
  
  return 0;
  
}
