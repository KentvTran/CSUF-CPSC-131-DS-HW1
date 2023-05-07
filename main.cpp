#include <iostream>
#include <memory>
#include <vector>

#include "GroceryItem.hpp"
int main()
{
  std::cout << "Welcome to Target. " << "Place grocery items into your shopping cart by entering each item's information. " <<
   "Enclose string entries in quotes, separate fields with comas." << std::endl;

  std::vector<std::unique_ptr<GroceryItem>> items;
  while( std::cin )
  {
    std::cout << "Enter UPC, Product Brand, Product Name, and Price" << std::endl;
    auto item = std::make_unique<GroceryItem>();
    std::cin >> *item;
    if( std::cin )
    {
      items.push_back( std::move( item ) );
      std::cout << "Item added to shopping cart: " << *items.back() << std::endl;
    }
  }

  std::cout << std::endl
            << "Here is an itemized list of the items in your shopping cart:" << std::endl;
  for( auto it = items.rbegin(); it != items.rend(); ++it )
  {
    std::cout << **it << std::endl;
  }
  return 0;
}
