class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        '''
        state:
        0: start with 'blank'
        1: sign before e
        2: digit before dot
        3: digit after dot
        4: blank before dot and digit after dot (eg: .123 means 0.123)
        5: e
        6: sign after e
        7: digit after e 
        8: end with 'blank'
        
        's' : sign
        'd' : digit
        'e' : e
        '.' : dot
        ' ' : blank
        '''
        states = [{' ': 0, 's': 1, 'd': 2, '.': 4},
                  {'d': 2, '.': 4},
                  {'d': 2, '.': 3, 'e': 5, ' ': 8},
                  {'d': 3, 'e': 5, ' ': 8},
                  {'d': 3},
                  {'s': 6, 'd': 7},
                  {'d': 7},
                  {'d': 7, ' ': 8},
                  {' ': 8}
                  ]
        p = 0
        for c in s:
            if '0' <= c <= '9':  # digit
                t = 'd'
            elif c in '+-':  # sign
                t = 's'
            elif c in 'eE':  # e
                t = 'e'
            elif c in '. ':  # dot or blank
                t = c
            else:  # unknown
                t = '?'

            if t not in states[p]:
                return False
            p = states[p][t]
        return p in (2, 3, 7, 8)


if __name__ == '__main__':
    s = '+-5'
    obj = Solution()
    result = obj.isNumber(s)
    print(result)
