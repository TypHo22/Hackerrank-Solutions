#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'mostBalancedPartition' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY parent
 *  2. INTEGER_ARRAY files_size
 */

class Node
{
public:
    Node():index_(-1){}
    Node(int index, int size,int depth):
        index_(index), size_(size), total_(size), depth_(depth)
    {

    }

    int sumUp()
    {
        int sum = size_;

        for(auto& c : childs_)
            sum += c->sumUp();

        auto it = depthSum_.find(index_);
        if(it == depthSum_.end())
        {
            depthSum_.insert({depth_,size_});
        }
        else
        {
            it->second += size_;
        }

        total_ = sum;
        return sum;
    }

    int index_;
    int size_;
    int total_;
    int depth_;
    static std::map<int,int> depthSum_;
    std::vector<Node*> childs_;
};
std::map<int,int> Node::depthSum_;

void balanceLimit(Node* root, const int total , int& diff)
{
    int d = abs(total - root->total_ * 2);
    if(d < diff) diff = d;
        for(Node* child : root->childs_)
            balanceLimit(child, total, diff);
}

int mostBalancedPartition(vector<int> parent, vector<int> files_size)
{
    vector<Node> nodes(parent.size());
    Node* root = &nodes.front();
    for(size_t a = 0; a < parent.size(); a++)
    {
        const int index = parent[a];
        nodes[a] = Node(a, files_size[a],index);

        /*
         Tricky part of the task to understand how relationships are defined between nodes
         lets assume for parent = {-1, 0, 0, 1, 1, 2}
         parent[i] = j, and i is a subdirectory of  j
         parent[0] = -1 => root
         parent[1] = 0  => parent[1] is a child of parent[0]
         parent[2] = 0  => parent[2] is a child of parent[0]
         parent[3] = 1  => parent[3] is a child of parent[1]
         parent[4] = 1  => parent[4] is a child of parent[1]
         parent[5] = 2  => parent[5] is a child of parent[2]
         parent[i] is a child of parent[j]
         */
        if(index < 0)
            continue;

        nodes[index].childs_.push_back(&nodes[a]);

    }

    int sum = root->sumUp();
    int diff = sum;


    balanceLimit(root,sum,diff);


    return diff;
}

void check(int solA, int solB, int i)
{
    (solA != solB) ? cout<<"Wrong case: " << i << endl : cout<<"Correct case: " << i << endl;
}

int main()
{
    vector<int> parent_ex = {-1, 0, 0, 1, 1, 2};
    vector<int> fileSi_ex = { 1, 2, 2, 1, 1, 1};
    check(mostBalancedPartition(parent_ex,fileSi_ex),0,-1);

    vector<int> parent_0 = {-1, 0, 1, 2};
    vector<int> fileSi_0 = {1, 4, 3, 4};
    check(mostBalancedPartition(parent_0,fileSi_0),2,0);

    vector<int> parent_1 = {-1, 0, 0, 0};
    vector<int> fileSi_1 = {10, 11, 10, 10};
    check(mostBalancedPartition(parent_1,fileSi_1),19,1);


    vector<int> parent_2 = {-1, 0};
    vector<int> fileSi_2 = {20, 100};
    check(mostBalancedPartition(parent_2,fileSi_2),80,2);

    vector<int> parent_3 = {-1, 0, 0, 0, 0, 3, 4, 6, 0, 3};
    vector<int> fileSi_3 = {298, 2187, 5054, 266, 1989, 6499, 5450, 2205, 5893, 8095};
    check(mostBalancedPartition(parent_3,fileSi_3),8216,3);


    vector<int> parent_4 = {-1, 0, 1, 2, 1, 0, 5,2 ,0 ,0};
    vector<int> fileSi_4 = {8475, 6038, 8072, 7298, 5363, 9732, 3786, 5521, 8295, 6186};
    check(mostBalancedPartition(parent_4,fileSi_4),4182,4);


    vector<int> parent_5 = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> fileSi_5 = {8618, 5774, 7046, 459, 2279, 2894, 798, 2328, 1011, 2780};
    check(mostBalancedPartition(parent_5,fileSi_5),5203,5);

    return 0;
}
