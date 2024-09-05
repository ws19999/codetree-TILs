fun main()
{
    var (n,a) = readLine()!!.split(" ")
    var answer=""
    var cnt=0
    for(i in 1..n.toInt()) {
        val str = readLine()!!
        if (str[3] == a[0]) {
            if (cnt != 0) answer += "\n"
            answer += str
            cnt++
        }
    }
    println(cnt)
    print(answer)
}