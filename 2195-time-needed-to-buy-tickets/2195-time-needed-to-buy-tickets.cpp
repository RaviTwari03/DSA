class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    //     int time = 0;
    //     for (int i = 0; i < tickets.size(); i++) {
    //         if (i <= k)
    //             time += min(tickets[i], tickets[k]);
    //         else
    //             time += min(tickets[i], tickets[k] - 1);
    //     }
    //     return time;
    // }
    queue<int>q;  
    int n = tickets.size();

    for(int i = 0;i<n;i++)
        q.push(i);
    
    int time =0;
    while(tickets[k]!=0){
        tickets[q.front()]--;
        if(tickets[q.front()])
            q.push(q.front());
            q.pop();
            time++;
        
       
    }
     return time;
    }
};
