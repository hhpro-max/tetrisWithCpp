#include <iostream>
struct Place
{
    std::string firstBlock = "[";
    int mainInt = 0;
    std::string lastBlock = "]";
    bool moved = false;
};

class Space{
    public :
        Place shapeI[1][4];
        Place shapeL[3][2];
        Place shapeO[2][2];
        Place shapeZ[2][3];
        Place shapeT[2][3];
        void initShapes(){
            //init shapeI
            Place place;
            Place blank;
            place.mainInt = 1;
            for(int i = 0;i < 4;i++){
                shapeI[0][i] = place;
            }
            //init shapeL
            place.mainInt = 2;
            for(int i = 0;i<3;i++){
                for(int j = 0 ; j < 2 ; j++){
                    if(j == 0 || (i == 2 && j==1)){
                        shapeL[i][j] = place;
                    }else{
                        shapeL[i][j] = blank;
                    }
                }
            }
            //init shapeO
            place.mainInt =3;
            for(int i = 0;i<2;i++){
                for(int j = 0 ; j < 2 ; j++){
                    
                        shapeO[i][j] = place;
                    
                }
            }
            //init shapeZ
            place.mainInt=4;
            for(int i = 0;i<2;i++){
                for(int j = 0 ; j < 3 ; j++){
                    if((i == 0 && j!=2 ) || (i == 1 && j!=0)){
                        shapeZ[i][j] = place;
                    }else{
                        shapeZ[i][j] = blank;
                    }
                }
            }
            //init shapeT
            place.mainInt=4;
            for(int i = 0;i<2;i++){
                for(int j = 0 ; j < 3 ; j++){
                    if((i == 0 ) || (i == 1 && j!=0 && j!=2)){
                        shapeT[i][j] = place;
                    }else{
                        shapeT[i][j] = blank;
                    }
                }
            }
        }
        Place *activeShape = nullptr;
        int rows = 20;
        int columns = 10;
        Place space[20][10];
        void initSpace(){
            for(int i = 0;i < rows;i++){
                for(int j = 0 ; j < columns;j++){
                    Place place;
                    
                    space[i][j] = place;
                }
            }
        }
        void printSpace(){
            std::cout << "********************************" << "\n";
            for(int i = 0;i < rows;i++){
                std::cout << "*";
                for(int j = 0 ; j < columns;j++){
                    std::cout << space[i][j].firstBlock + std::to_string(space[i][j].mainInt) + space[i][j].lastBlock;
                }
                std::cout << "*" <<"\n";
            }
            std::cout << "********************************" << "\n";
        }
        void moveDown(int avticeNum){
            for(int i = rows -1 ; i >= 0 ; i--){
                for (int j = columns -1;j >= 0 ; j--){
                    if (i!=rows - 1 && space[i][j].mainInt==avticeNum && !space[i][j].moved){
                        int temp = space[i][j].mainInt;
                        space[i+1][j].mainInt = temp;
                        space[i][j].mainInt = 0;
                        space[i+1][j].moved = true;
                    }
                }
            }
            resetMovedBlock();
        }
        void resetMovedBlock(){
            for(int i = 0 ; i < rows ; i++){
                for (int j = 0;j < columns ; j++){
                    space[i][j].moved = false;
                }
            }
        }
        template <size_t pRows, size_t pCols>
        void spawnNewItem(Place (&arr)[pRows][pCols]) {
            for (int i = 0; i < pRows; i++) {
            for (int j = 0; j < pCols; j++) {
                space[i][j].mainInt = arr[i][j].mainInt;
            }
            
        }
}
        
    Space(){
        initShapes();
        initSpace();
        spawnNewItem(shapeI);
    }    
};