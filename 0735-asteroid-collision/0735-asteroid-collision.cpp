class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            if(st.empty())
            {
                st.push(asteroids[i]);
                continue;
            }
            if(asteroids[i]<0)
            {
                int x = st.top();
                if(x<0)
                {
                    st.push(asteroids[i]);
                    continue;
                }
                if(abs(x)==abs(asteroids[i]))
                {
                    st.pop();
                    continue;
                }
                else
                {
                    if(abs(x)>abs(asteroids[i]))
                    {
                        continue;
                    }
                    else
                    {
                        while(abs(st.top())<abs(asteroids[i]) && !st.empty())
                        {
                            st.pop();
                            if(st.empty())
                            {
                                break;
                            }
                            if(st.top()<0)
                            {
                                break;
                            }
                            
                        }
                        if(st.empty())
                        {
                            st.push(asteroids[i]);
                            continue;
                        }
                        if(st.top()<0)
                        {
                            st.push(asteroids[i]);
                            continue;
                        }
                        if(abs(st.top())==abs(asteroids[i]))
                            {
                                st.pop();
                                continue;
                            }
                        if(st.top()>abs(asteroids[i]))
                        {
                            continue;
                        }
                        else
                        {
                            // st.pop();
                            st.push(asteroids[i]);
                        }
                    }
                }
            }
            else
            {
                if(asteroids[i]>0 && st.top()<0)
                {
                    st.push(asteroids[i]);
                    continue;
                }
                int x = st.top();
                if(x>0)
                {
                    st.push(asteroids[i]);
                    continue;
                }
                // if(abs(x)==abs(asteroids[i]) && x>)
                // {
                //     st.pop();
                //     continue;
                // }
                else
                {
                    while(abs(st.top())<abs(asteroids[i]) && !st.empty())
                    {
                        st.pop();
                        if(st.empty() || st.top()<0)
                        {
                            break;
                        }
                        if(st.top()>0)
                        {
                            break;
                        }
                    }
                    if(st.empty())
                    {
                        st.push(asteroids[i]);
                        continue;
                    }
                    if(abs(st.top())>abs(asteroids[i]))
                    {
                        continue;
                    }
                    if(abs(st.top())==abs(asteroids[i]))
                            {
                                st.pop();
                                continue;
                            }
                    else
                    {
                        // st.pop();
                        st.push(asteroids[i]);
                    }
                }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};