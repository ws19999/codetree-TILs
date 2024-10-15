fun main()
{
    var lists=IntArray(10)
    var num=1
    for(i in 1..3)
    {
        var n=readLine()!!.toInt()
        num*=n
    }
    while(num>0)
    {
        lists[num%10]++
        num/=10
    }
    for(i in 0..9)println(lists[i])
}