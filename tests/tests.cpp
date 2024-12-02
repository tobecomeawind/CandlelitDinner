#include <vector>
#include <iostream>
#include <functional>

#include "tests.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

void initTests(void)
{
  // Body Contain Tests
  tests.push_back(BodyContainTest1);
  tests.push_back(BodyContainTest2);
  tests.push_back(BodyContainTest3);

  // Contains
  tests.push_back(ContainTest1);
  tests.push_back(ContainTest2);
  tests.push_back(ContainTest3);
 
  // Full size
  tests.push_back(FullSizeTest1);
  tests.push_back(FullSizeTest2);
  tests.push_back(FullSizeTest3);
  
  // Body size
  tests.push_back(BodySizeTest1);
  tests.push_back(BodySizeTest2);
  tests.push_back(BodySizeTest3);
  
  // Is red 
  tests.push_back(IsRedTest1);
  tests.push_back(IsRedTest2);
  tests.push_back(IsRedTest3);
  
  // Is green
  tests.push_back(IsGreenTest1);
  tests.push_back(IsGreenTest2);
  tests.push_back(IsGreenTest3);
}

int launchTests(void)
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}


// Было несколбко вариантов развития событий
//
// Запихнуть все три теста в один и вернуть общий результат трёх тестов
// Тоесть:
//     return object.testFunc(value1) && 
//            object.testFunc(value2) &&
//            object.testFunc(value3) 
//
// Это весьма не логично потому что если условно будет 1000 тестов в одной функции
// То я просто не смогу сразу узнать где находится моя ошибка
//
//
// Был вариант сделать wrapper, который бы возвращал ссылку на функцию
// Такое возможно сделать, но я не просто хочу получить адресс этой функции
// Я хочу получить адресс, предоставляя аргументы данной функции
// Примерно вот так
// 		&(func(TestCandleObject, TestVerifiableValue) 
// Но плюсы, да даже не плюсы, а я просто не могу понять как это реализовать
// Вроде вернуть адресс просто функции могу , а с аргументами проблема
// Я пробовал лямбды, но безуспешно
//
//
// Поэтому всё что написано ниже такой дичайший колхоз просто
// Это очень не красиво и очень не универсально по сравнению с wrapper(ом)
//



Candle Object(241.12, 244.89, 233.89, 243.11);
//--------------
// Body contain
//--------------
static bool BodyContainTest1(void)
{
	// Тест проходит хотя значение оставляет желать лучшего	
	
	return Object.body_contains(241.119999999999999); 
}


static bool BodyContainTest2(void)
{
	return Object.body_contains(243.1100000000000001); 
}


static bool BodyContainTest3(void)
{
	return Object.body_contains(242.2); 
}



//--------------
// Contain
//--------------
static bool ContainTest1(void)
{	
	return Object.contains(244.890000000000000001); 
}

static bool ContainTest2(void)
{	
	return Object.contains(233.889999999999999999); 
}

static bool ContainTest3(void)
{	
	return Object.contains(233.99); 
}



//--------------
// Full size
//--------------
static bool FullSizeTest1(void)
{	
	return Object.full_size(); 
}

static bool FullSizeTest2(void)
{	
	Candle Object(999, 15.9813, 5, 999);	
	return Object.full_size() == 10.9813; 
}

static bool FullSizeTest3(void)
{	
	Candle Object(999, 0, -1, 999);	
	return Object.full_size() == 1; 
}



//--------------
// Body size
//--------------
static bool BodySizeTest1(void)
{	
	return Object.body_size(); 
}

static bool BodySizeTest2(void)
{	
	Candle Object(15.9813, 999, 999, 5);	
	return Object.body_size() == 10.9813; 
}

static bool BodySizeTest3(void)
{	
	Candle Object(0, 999, 999, -1);	
	return Object.body_size() == 1; 
}




//--------------
// Is red
//--------------
static bool IsRedTest1(void)
{	
	return Object.body_size(); 
}

static bool IsRedTest2(void)
{	
	Candle Object(15.9813, 0, 0, 15.9812);	
	return Object.is_red(); 
}

static bool IsRedTest3(void)
{	
	Candle Object(1, 999, 999, 0.99999);	
	return Object.is_red(); 
}



//--------------
// Is green
//--------------
static bool IsGreenTest1(void)
{	
	return Object.is_green(); 
}

static bool IsGreenTest2(void)
{	
	Candle Object(15.981, 0, 0, 15.9812);	
	return Object.is_green(); 
}

static bool IsGreenTest3(void)
{	
	Candle Object(-1, 999, 999, -0.99999);	
	return Object.is_green(); 
}
