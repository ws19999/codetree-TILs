fun main()
{
    var (x,y)=readLine()!!.split(" ").map{it.toInt()}
    var average:Double=0.0
    var sums=0
    if(x>y)
    {
        var temp=x
        x=y
        y=temp
    }
    var cnt=0
    for(i in x..y)
    {
        if(i%5!=0)
        {
            cnt+=1
            sums+=i
        }
    }
    average=sums.toDouble()/cnt.toDouble()
    print("${sums} ${String.format("%.1f",average)}")
}