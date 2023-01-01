class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s_l = s.split()
        if len(pattern) != len(s_l):
            # print("LEN DIFF")
            return False
        
        d_p_s = dict()
        d_s_p = dict()
        for p_c, s_c in zip(pattern, s_l):
            # print("Main", p_c, s_c)
            if p_c in d_p_s:
                if d_p_s[p_c] != s_c:
                    # print("X", p_c, s_c)
                    return False
            else:
                d_p_s[p_c] = s_c
            
            if s_c in d_s_p:
                if d_s_p[s_c] != p_c:
                    # print("Y",p_c, s_c)
                    return False
            else:
                d_s_p[s_c] = p_c
            
        
        
        return True