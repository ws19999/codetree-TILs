import kotlin.math.max
import kotlin.math.min
fun main()
{
    val lists=readLine()!!.split(" ").map{it.toInt()}
    var maxx=-1000
    var minn=1000
    for(i in 0..99)
    {
        if(lists[i]==-999)break
        maxx=max(maxx,lists[i])
        minn=min(minn,lists[i])
    }
    print("${maxx} ${minn}")
}