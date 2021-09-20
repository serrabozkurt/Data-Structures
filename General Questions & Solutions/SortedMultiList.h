void question4();
struct mnode{
public:
	int data;
    mnode* next;
    mnode* root;
};

struct Multilist
{
public:
    mnode* headptr;
	void create();
    void add(int);
    void printroots(mnode*);
    mnode* returnadressof(int);
};