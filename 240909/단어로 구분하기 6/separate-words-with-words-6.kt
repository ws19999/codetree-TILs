fun main()
{
    val lists=readLine()!!.split(" ")
    val len=lists.size
    for(i in 0..len-1)
    {
        if((i+1)%3==0)println(lists[i])
    }
}