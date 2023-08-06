#include <iostream>
#include<cstdlib>
struct Place
{
    std::string firstBlock = "[";
    int mainInt = 0;
    std::string lastBlock = "]";
    bool movedDown = false;
    bool movedSide = false;
    bool locked = false;
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
            place.mainInt=5;
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
        
        int rows = 20;
        int columns = 10;
        Place space[20][10];
        int activeNum;
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
        void moveDown(){
            for(int i = rows -1 ; i >= 0 ; i--){
                for (int j = columns -1;j >= 0 ; j--){
                    
                    if (i!=rows - 1 && space[i][j].mainInt==activeNum && !space[i][j].movedDown && !space[i][j].locked && !space[i+1][j].locked && checkForMoveDown(i + 1)){
                        
                        int temp = space[i][j].mainInt;
                        space[i+1][j].mainInt = temp;
                        space[i][j].mainInt = 0;
                        space[i+1][j].movedDown = true;
                        
                        
                    }
                    
                }
            }
            checkToLockMoveDown();
            checkToLockLastRaw();
            resetMovedDownBlock();
        }
        void checkToLockMoveDown(){
            for(int i = 0 ; i < rows ; i++){
                for (int j = 0;j < columns ; j++){
                        if (space[i][j].mainInt != 0 && space[i+1][j].mainInt != 0 && !space[i][j].locked && space[i+1][j].locked){
                        lockEveryThing();
                        break;
                    
                    
                    }
                    }
                }
        }
        bool checkForMoveDown(int rowNum){
            
            
                for (int j = columns -1;j >= 0 ; j--){
                    if (space[rowNum][j].mainInt != 0 && space[rowNum-1][j].mainInt != 0 && !space[rowNum-1][j].locked){
                        //lockEveryThing();
                        return false;
                    
                    
                    }
                }
                
            
            return true;
        }
        void lockEveryThing(){
            
            for(int i = rows -1 ; i >= 0 ; i--){
                for (int j = columns -1;j >= 0 ; j--){
                    if (space[i][j].mainInt != 0)
                    {
                        space[i][j].locked = true;
                    }
                    
                }
            }
            spawnNewItem();
            
        }
        void checkToLockLastRaw(){
            
            for (int i = 0;i < columns;i ++)
            {
                if(space[rows-1][i].mainInt != 0 && !space[rows-1][i].locked){
                    /*space[rows-1][i].locked = true;
                    if(!newItem){
                        spawnNewItem();
                        newItem = true;
                    }*/
                    lockEveryThing();
                    break;
                }
            }
            
        }
        void resetMovedDownBlock(){
            for(int i = 0 ; i < rows ; i++){
                for (int j = 0;j < columns ; j++){
                    space[i][j].movedDown = false;
                    
                }
            }
        }
        template <size_t pRows, size_t pCols>
        void generateItem(Place (&arr)[pRows][pCols]) {
            for (int i = 0; i < pRows; i++) {
            for (int j = 0; j < pCols; j++) {
                space[i][j].mainInt = arr[i][j].mainInt;
            } 
        }
        for (int i = 0; i < pRows; i++) {
            for (int j = 0; j < pCols; j++) {
                if(arr[i][j].mainInt!=0){
                    activeNum = arr[i][j].mainInt;
                    break;
                }

            }
        }
        }
        void spawnNewItem() {
            std::srand((unsigned) time(NULL));
            int random = rand() % 5;
            int pRows;
            int pCols;
            
            
            switch(random){
                case 0 :    generateItem(shapeI);
                            break;
                case 1 :    generateItem(shapeO);
                            break;
                case 2 :    generateItem(shapeZ);
                            break;
                case 3 :    generateItem(shapeL);
                            break;
                case 4 :    generateItem(shapeT);
                            break;            
            };
        }
        void moveSide(char &move){
            int moveInt = 0;
            switch (move)
            {
                case 'a' :  moveInt = -1;
                            for(int i = 0 ; i < rows ; i++){
                                for (int j = 0 ; j < columns ; j++){
                                    if((j+moveInt < columns && j+moveInt>=0) && space[i][j].mainInt==activeNum && !space[i][j].movedSide && !space[i][j].locked && checkForMoveSide(j+moveInt,moveInt)){
                                        int temp = space[i][j].mainInt;
                                        space[i][j+moveInt].mainInt = temp;
                                        space[i][j].mainInt = 0;
                                        space[i][j+moveInt].movedSide = true;
                        
                                    }
                                }
                            }
                            break;
                case 'd' :  moveInt = +1;
                            for(int i = rows - 1 ; i >= 0 ; i--){
                                for (int j =columns-1 ; j >= 0 ; j--){
                                    if((j+moveInt < columns && j+moveInt>=0) && space[i][j].mainInt==activeNum && !space[i][j].movedSide && !space[i][j].locked && checkForMoveSide(j+moveInt,moveInt)){
                                        int temp = space[i][j].mainInt;
                                        space[i][j+moveInt].mainInt = temp;
                                        space[i][j].mainInt = 0;
                                        space[i][j+moveInt].movedSide = true;
                        
                                    }
                                }
                            }
                            break;
            
            }
            
            move = NULL;
            resetMovedSideBlock();
        }
        bool checkForMoveSide(int colNum, int moveInt){
            for (int i = 0; i < rows;i++){
                
                if(space[i][colNum].mainInt!=0 && space[i][colNum-moveInt].mainInt!=0 && !space[i][colNum-moveInt].locked){
                    return false;
                }
            }
            return true;
        }
        void resetMovedSideBlock(){
            for(int i = 0 ; i < rows ; i++){
                for (int j = 0;j < columns ; j++){
                    space[i][j].movedSide = false;
                    
                }
            }
        }
        
    Space(){
        initShapes();
        initSpace();
        spawnNewItem();
    }    
};