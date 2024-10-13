fun main()
{
    var n=readLine()!!.toInt()
    var sums=0
    var temp=1000
    for(i in 0..1000)
    {
        temp-=i*2
        sums+=i*2
        if(temp<=n)
        {
            print("${i} ${sums}")
            break
        }
    }
}