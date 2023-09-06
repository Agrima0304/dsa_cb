class Solution{
public:
    void Add_item(stack<int> &St,int x)
    {
     if(St.empty())
     {
         St.push(x);
         return;
     }
     int data=St.top();
     St.pop();
     Add_item(St,x);
     St.push(data);
    }
    void Reverse(stack<int> &St){
        //base case
        if(St.empty())
        {
            return ;
        }
        //recursive case
        int x=St.top();
        St.pop();
        Reverse(St);
        Add_item(St,x);
    }
