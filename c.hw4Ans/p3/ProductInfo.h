#define boolean char
#define true 1
#define false 0

typedef enum {book, keychain, t_shirt, mug} Type;
typedef enum {copper, steel, wood, plastic } Material;
typedef enum {XS, S, M, L, XL, XXL} Size;
typedef enum {beach, mountain, village} Pattern;

typedef struct 
{
  int productID;
  float price;
  Type type;
  union
  {
      char author[20];
      Material material;
      Size size;
      Pattern pattern;
  } attribute;
} Product;
                        
void showHelp();
Product getAProductInfo();
void showAllProductInfo(Product products[], int count);
void searchProduct(Product products[], int count, int id);
