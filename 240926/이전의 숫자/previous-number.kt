fun main()
{
    val n=readLine()!!.toInt()
    val lists=readLine()!!.trim().split(" ").map{it.toInt()}
    for(i in 0..n-1)
    {
        if(lists[i]==0)
        {
            var answer=0
            for(j in i-1 downTo i-5)answer+=lists[j]
            print(answer)
            break
        }
    }
}