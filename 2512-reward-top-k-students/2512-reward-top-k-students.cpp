#define pi pair<int,int>
class comp
{
     public:
     bool operator()(pi &p1, pi &p2)
     {
      if(p1.first==p2.first)
        return p1.second>p2.second;
      return p1.first<p2.first;
     }    
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) 
    {
        unordered_set<string> pos,neg;
        for(int i=0;i<positive_feedback.size();i++)
        {
            pos.insert(positive_feedback[i]);
        }
        for(int i=0;i<negative_feedback.size();i++)
        {
            neg.insert(negative_feedback[i]);
        }
        priority_queue<pi,vector<pi>,comp> pq;
        int n=student_id.size();
        for(int i=0;i<n;i++)
        {
            string word="";
            int score=0;
            for(int j=0;j<report[i].size();j++)
            {
                if(report[i][j] == ' ')
                {
                    if(pos.find(word) != pos.end())
                    {
                        score += 3;
                    }
                    if(neg.find(word) != neg.end())
                    {
                        score -= 1;
                    }
                    word="";
                }
                else
                {
                    word += report[i][j];   
                }
            }
            
            if(pos.find(word) != pos.end())
            {
                score+=3;
            }
            if(neg.find(word) != neg.end())
            {
                score -= 1;
            }
            
            word="";
            pq.push({score , student_id[i]});
        }
        
        vector<int> ans;
        while(k--)
        {
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        
        return ans;
    }
};