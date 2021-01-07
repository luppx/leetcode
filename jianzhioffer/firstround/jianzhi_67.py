class Solution(object):
    def strToInt(self, str):
        """
        :type str: str
        :rtype: int
        """
        if not str:
            return 0
        i = 0
        while i < len(str) and str[i] == ' ':
            i += 1
        if i == len(str) or str[i] not in '-+0123456789':  # 用in会遍历字符串的每个元素，尽量用比较符号(<,>等)来判断，速度快些
            return 0
        elif str[i] in '-+' and i+1 == len(str):
            return 0
        elif str[i] in '-+' and not '0' <= str[i+1] <= '9':
            return 0

        sign = -1 if str[i] == '-' else 1
        num = 0 if str[i] in '-+' else ord(str[i]) - ord('0')  # ord()：求某个字符的ascii码值；ascii()：将整数或字符转为ascii码，如59转为'9'

        max_num = pow(2, 31)
        int_max = max_num - 1
        int_min = -max_num
        boundary = max_num // 10
        for s in str[i+1:]:
            if not '0' <= s <= '9':
                break
            # 每轮拼接前都比较数字是否越界，越界则提前返回
            elif num > boundary or (num == boundary and s > '7'):
                return int_max if sign == 1 else int_min
            num = 10 * num + ord(s) - ord('0')
        return num * sign


if __name__ == '__main__':
    strs = " "
    obj = Solution()
    result = obj.strToInt(strs)
    print(result)
