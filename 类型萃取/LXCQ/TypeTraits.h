#define _CRT_SECURE_NO_WARNING
struct TrueType
{
	bool Get()
	{
		return true;
	}
};
struct FalseType
{
	bool Get()
	{
		return false;
	}
};
template<typename T>
struct TypeTraits
{
	typedef FalseType isPodType;//ÄÚÇ¶ÐÍ±ð
};
template<>
struct TypeTraits<int>
{
	typedef TrueType isPodType;
};
template<>
struct TypeTraits<char>
{
	typedef TrueType isPodType;
};
template<>
struct TypeTraits<float>
{
	typedef TrueType isPodType;
};
template<>
struct TypeTraits<unsigned char>
{
	typedef TrueType isPodType;
}; 
template<>
struct TypeTraits<double>
{
	typedef TrueType isPodType;
}; 