#include "JaroWinkler.h"

double JaroObj::jaroDistance(const std::string& a, const std::string& b)
{
    int aLength(a.size());
    int bLength(b.size());
    if (aLength == 0 || bLength == 0)
    {
        return 0.0;
    }
    int maxRange(std::max(0, std::max(aLength, bLength) / 2 - 1));
    std::vector<bool> aMatch(aLength, false);
    std::vector<bool> bMatch(bLength, false);
    int matchingCharacters(0);
    for (int aIndex(0); aIndex < aLength; ++aIndex)
    {
        int minIndex(std::max(aIndex - maxRange, 0));
        int maxIndex(std::min(aIndex + maxRange + 1, bLength));
        
        if (minIndex >= maxIndex)
        {
            break;
        }
        
        for (int bIndex(minIndex); bIndex < maxIndex; ++bIndex)
        {
            if (!bMatch.at(bIndex) && a.at(aIndex) == b.at(bIndex))
            {
                aMatch[aIndex] = true;
                bMatch[bIndex] = true;
                ++matchingCharacters;
                break;
            }
        }
    }
    if (matchingCharacters == 0)
    {
        return 0.0;
    }
    std::vector<int> aPosition(matchingCharacters, 0);
    std::vector<int> bPosition(matchingCharacters, 0);
    
    for (int aIndex(0), positionIndex(0); aIndex < aLength; ++aIndex)
    {
        if (aMatch.at(aIndex))
        {
            aPosition[positionIndex] = aIndex;
            ++positionIndex;
        }
    }
    
    for (int bIndex(0), positionIndex(0); bIndex < bLength; ++bIndex)
    {
        if (bMatch.at(bIndex))
        {
            bPosition[positionIndex] = bIndex;
            ++positionIndex;
        }
    }
    int transpositions(0);
    for (int index(0); index < matchingCharacters; ++index)
    {
        if (a.at(aPosition.at(index)) != b.at(bPosition.at(index)))
        {
            ++transpositions;
        }
    }
    return (
        WeightStringA * matchingCharacters / aLength +
        WeightStringB * matchingCharacters / bLength +
        WeightTranpose * (matchingCharacters - transpositions / 2) / matchingCharacters
    );
}





double JaroObj::jaroWinklerDistance(const std::string&a, const std::string& b)
{
    double distance(jaroDistance(a, b));
    
    if (distance > BoostThreshold)
    {
        int commonPrefix(0);
        for (int index(0), indexEnd(min(std::min(a.size(), b.size()), PrefizSize)); index < indexEnd; ++index)
        {
            if (a.at(index) == b.at(index))
            {
                ++commonPrefix;
            }
            else
            {
                break;
            }
        }
        
        distance += ScalingFac * commonPrefix * (1.0 - distance);
    }
    
    return distance;
}