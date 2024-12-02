fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val n=readLine()!!.toInt()
    var arr=MutableList(n){" "}
    for(i in 0..n-1)
    {
        arr[i]=readLine()!!
    }
    val c=readLine()!!
    var ans : MutableList<String> = mutableListOf()
    var answer=0
    for(i in arr)
    {
        if(i.endsWith(c[0]))
        {
            ans.add(i)
            answer++
        }
    }
    println("$answer")
    for(i in ans)println(i)
    bw.close()
}