#pragma once
#include <iostream>
#define uint unsigned int

/*
VibFlow is licensed under the MIT License 
Following file declares some of the main aspects
Major building structs are here
*/


namespace vflow
{
	//VibFlow main vector base
	template<typename T> struct VectorData2
	{
		T x;
		T y;
	};
	template<typename T> struct VectorData3
	{
		T x;
		T y;
		T z;
	};
	template<typename T> struct VectorData4
	{
		T x;
		T y;
		T z;
		T w;
	};

	template<typename U> struct Vec2
	{
	private:
		VectorData2<U> vdata;

	public:
		Vec2()
		{
			this->x = static_cast<U>(0);
			this->y = static_cast<U>(0);
		}

		Vec2(U x, U y)
		{
			this->x = x;
			this->y = y;
		}

		Vec2<U>& operator=(const Vec2<U>& other)
		{
			this->vdata.x = other.vdata.x;
			this->vdata.y = other.vdata.y;
			return *this;
		}

		Vec2<U>& operator+(const Vec2<U>& other)
		{
			this->vdata.x += other.vdata.x;
			this->vdata.y += other.vdata.y;
			return *this;
		}

		Vec2<U>& operator-(const Vec2<U>& other)
		{
			this->vdata.x -= other.vdata.x;
			this->vdata.y -= other.vdata.y;
			return *this;
		}

		inline bool operator==(const Vec2<U>& other)
		{
			return (this->vdata.x == other.vdata.x || this->vdata.y == other.vdata.y);
		}

		inline bool operator!=(const Vec2<U>& other)
		{
			return !(operator==(other));
		}

		Vec2<U>& operator*(const U& other)
		{
			this->vdata.x *= other;
			this->vdata.y *= other;
			return *this;
		}

		VectorData2<U>* operator&()
		{
			return &(this->vdata);
		}

		double length()
		{
			return std::sqrt(x * x + y * y);
		}

		void normalize()
		{
			//Assuming we're not calling this in uvec and ivec scenarios
			x /= x;
			y /= y;
		}

		U& x = vdata.x;
		U& y = vdata.y;

		U& u = vdata.x;
		U& v = vdata.y;
	};
	template<typename U> struct Vec3
	{
	private:
		VectorData3<U> vdata;

	public:
		Vec3()
		{
			this->x = static_cast<U>(0);
			this->y = static_cast<U>(0);
			this->z = static_cast<U>(0);
		}

		Vec3(U x, U y, U z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vec3<U>& operator=(const Vec3<U>& other)
		{
			this->vdata.x = other.vdata.x;
			this->vdata.y = other.vdata.y;
			this->vdata.z = other.vdata.z;
			return *this;
		}

		Vec3<U>& operator+(const Vec3<U>& other)
		{
			this->vdata.x += other.vdata.x;
			this->vdata.y += other.vdata.y;
			this->vdata.z += other.vdata.z;
			return *this;
		}

		Vec3<U>& operator-(const Vec3<U>& other)
		{
			this->vdata.x -= other.vdata.x;
			this->vdata.y -= other.vdata.y;
			this->vdata.z -= other.vdata.z;
			return *this;
		}

		inline bool operator==(const Vec3<U>& other)
		{ 
			return (this->vdata.x == other.vdata.x || this->vdata.y == other.vdata.y || this->vdata.z == other.vdata.z);
		}

		inline bool operator!=(const Vec3<U>& other)
		{
			return !(operator==(other));
		}

		Vec3<U>& operator*(const U& other)
		{
			this->vdata.x *= other;
			this->vdata.y *= other;
			this->vdata.z *= other;
			return *this;
		}

		VectorData3<U>* operator&()
		{
			return &(this->vdata);
		}

		double length()
		{
			return std::sqrt(x*x + y*y + z*z);
		}

		void normalize()
		{
			//Assuming we're not calling this in uvec and ivec scenarios
			x /= x;
			y /= y;
			z /= z;
		}

		U& x = vdata.x;
		U& y = vdata.y;
		U& z = vdata.z;
	};
	template<typename U> struct Vec4
	{
	private:
		VectorData4<U> vdata;

	public:
		Vec4()
		{
			this->x = static_cast<U>(0);
			this->y = static_cast<U>(0);
			this->z = static_cast<U>(0);
			this->w = static_cast<U>(0);
		}

		Vec4(U x, U y, U z, U w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vec4<U>& operator=(const Vec4<U>& other)
		{
			this->vdata.x = other.vdata.x;
			this->vdata.y = other.vdata.y;
			this->vdata.z = other.vdata.z;
			this->vdata.w = other.vdata.w;
			return *this;
		}

		Vec4<U>& operator+(const Vec4<U>& other)
		{
			this->vdata.x += other.vdata.x;
			this->vdata.y += other.vdata.y;
			this->vdata.z += other.vdata.z;
			this->vdata.w += other.vdata.w;
			return *this;
		}

		Vec4<U>& operator-(const Vec4<U>& other)
		{
			this->vdata.x -= other.vdata.x;
			this->vdata.y -= other.vdata.y;
			this->vdata.z -= other.vdata.z;
			this->vdata.w -= other.vdata.w;
			return *this;
		}

		inline bool operator==(const Vec4<U>& other)
		{
			return (this->vdata.x == other.vdata.x || this->vdata.y == other.vdata.y || this->vdata.z == other.vdata.z || this->vdata.w == other.vdata.w);
		}

		inline bool operator!=(const Vec4<U>& other)
		{
			return !(operator==(other));
		}

		Vec4<U>& operator*(const U& other)
		{
			this->vdata.x *= other;
			this->vdata.y *= other;
			this->vdata.z *= other;
			this->vdata.w *= other;
			return *this;
		}

		VectorData4<U>* operator&()
		{
			return &(this->vdata);
		}

		double length()
		{
			return std::sqrt(x * x + y * y + z * z + w * w);
		}

		void normalize()
		{
			//Assuming we're not calling this in uvec and ivec scenarios
			x /= x;
			y /= y;
			z /= z;
			w /= w;
		}

		U& x = vdata.x;
		U& y = vdata.y;
		U& z = vdata.z;
		U& w = vdata.w;

		U& r = vdata.x;
		U& g = vdata.y;
		U& b = vdata.z;
		U& a = vdata.w;
	};

	typedef Vec2<float>  fvec2;
	typedef Vec2<double> dvec2;
	typedef Vec2<int>    ivec2;
	typedef Vec2<uint>   uvec2;

	typedef Vec3<float>  fvec3;
	typedef Vec3<double> dvec3;
	typedef Vec3<int>    ivec3;
	typedef Vec3<uint>   uvec3;

	typedef Vec4<float>  fvec4;
	typedef Vec4<double> dvec4;
	typedef Vec4<int>    ivec4;
	typedef Vec4<uint>   uvec4;
}
