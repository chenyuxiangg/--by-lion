//优化版
string addBinary(string a, string b) {
         string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += (i >= 0 ? a[i --] - '0' : 0);
            c += (j >= 0 ? b[j --] - '0' : 0);
            s = char(c % 2 + '0') + s;     //前一项充当该位结果，然后与原来的s相连接，
                                           //相当于在s前插入了该项 
            c /= 2;    //充当进位
        }
        return s;
    }

//普通版
string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string res = "";
        int alen = a.size();
        int blen = b.size();
        int i = 0;
        int c = 0;
        for(;i < alen && i < blen;++i){
            if(c > 0){
                if(a[i] == '1' && b[i] == '1'){
                    res += '1';
                    c = 1;
                }
                else if(a[i] == '1' || b[i] == '1'){
                    res += '0';
                    c = 1;
                }
                else{
                    res += '1';
                    c = 0;
                }
            }
            else{
                if(a[i] == '1' && b[i] == '1'){
                    res += '0';
                    c = 1;
                }
                else if(a[i] == '1' || b[i] == '1'){
                    res += '1';
                    c = 0;
                }
                else{
                    res += '0';
                    c = 0;
                }
            }
        }
        if(i < alen){
            for(int j = i;j < alen;++j){
                if(c > 0){
                    if(a[j] == '1'){
                        res += '0';
                        c = 1;
                    }
                    else{
                        res += '1';
                        c = 0;
                    }
                }
                else{
                    if(a[j] == '1'){
                        res += '1';
                        c = 0;
                    }
                    else{
                        res += '0';
                        c = 0;
                    }
                }
            }
        }
        if(i < blen){
            for(int j = i;j < blen;++j){
                if(c > 0){
                    if(b[j] == '1'){
                        res += '0';
                        c = 1;
                    }
                    else{
                        res += '1';
                        c = 0;
                    }
                }
                else{
                    if(b[j] == '1'){
                        res += '1';
                        c = 0;
                    }
                    else{
                        res += '0';
                        c = 0;
                    }
                }
            }
        }
        if(c > 0){
            res += '1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
