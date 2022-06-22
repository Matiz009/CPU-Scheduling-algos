#include <stdio.h>
#include <math.h>

int convertBin(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

long long convertDec(int n) {
  long long bin = 0;
  int rem, i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }

int main(){
    int pageSize = 4;
    int noOfBits = 5;
    int offSetBits = 2;
    int noOfPages = pow(2,(pageSize - offSetBits));
    int noOfFrames = pow(2,(noOfBits-offSetBits));
    //Main Memory
    char mm[8][4] = {{'-','-','-','-'},{'i','j','k','l'},{'m','n','o','p'},{'-','-','-','-'},{'-','-','-','-'},{'a','b','c','d'},{'e','f','g','h'},{'-','-','-','-'}};
    char pages[noOfPages][pageSize];
    int pageTable[4] = {5,6,1,2};

    //fill pages
    char c = 'a';
    for(int i = 0; i < noOfPages; i++){
        for(int j = 0; j < pageSize; j++){
          pages[i][j] = c;
          c++;
        }
    }

    //binary input
    int inbin[5];
    int pageNoBits = noOfBits - offSetBits;

    long long pg = 0;
    long long os = 0;

    printf("Enter Logical Address in Binary (%d-bits): ",noOfBits);
    scanf("%1d%1d%1d%1d%1d",&inbin[0],&inbin[1],&inbin[2],&inbin[3],&inbin[4]);

    //separating page bits from offset bits
    for(int i = 0; i < pageNoBits; i++){
        pg = pg*10 + inbin[i];
    }
    int decPG = convertBin(pg);

    //offset bits
    for(int i = pageNoBits; i < noOfBits; i++){
        os = os*10 + inbin[i];
    }

    int decOS = convertBin(os);
    int decFN = pageTable[decPG];

    //Physical address calculation
    int phyAdd = (decFN*4) + decOS;
    long long binFN;

    //Check if its valid address
    if(mm[decFN][decOS] == pages[decPG][decOS]){
        binFN = convertDec(phyAdd);
        printf("%lld",binFN);
    }
    else{
        printf("Invalid Address!!!!");
    }

}



  return bin;
}
