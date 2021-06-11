using namespace std;

class a{
    
};

class b: public a{

};

int main(){
    void test(a* kk);
    b* haha;
    test(haha);
}