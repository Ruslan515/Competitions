// https://leetcode.com/problems/valid-parentheses/
object Valid_Parentheses extends App {
    object Solution {
        def isValid(s: String): Boolean = {
            val my_dict = scala.collection.mutable.HashMap[Char, Int]().withDefaultValue(0)
            my_dict('(') = 0
            my_dict('{') = 0
            my_dict('[') = 0
            my_dict(')') = 0
            my_dict(']') = 0
            my_dict('}') = 0
            val new_dict = scala.collection.mutable.Map[Char, Char]()
            new_dict(')') = '('
            new_dict('}') = '{'
            new_dict(']') = '['

            val op = Set('(', '[', '{')
            var temp: List[Char]
            for (char <- s) {
                if (op(char)) {
                    my_dict(char) += 1
                    temp.appended(char)
                }
                else {
                    val t = new_dict(char)
                    my_dict(t) -= 1
                    val s_t = temp(-1)
                    if (my_dict(t) < 0 || temp != s_t) {
                        return false
                    }

                }
            }

            return true
        }
    }

//    println(Solution.isValid("()"))
//    println(Solution.isValid("()[]{}"))
//    println(Solution.isValid("(]"))
//    println(Solution.isValid("([)]"))
    println(Solution.isValid("{[]}"))

}
