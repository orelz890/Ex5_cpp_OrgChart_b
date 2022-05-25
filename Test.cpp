// How to run:
// g++ sources/OrgChart.cpp Test.cpp sources/my_iterator.hpp sources/my_iterator.cpp sources/OrgChart.hpp doctest.h TestRunner.cpp -o my_test
#include "doctest.h"
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "sources/OrgChart.hpp"
#include "sources/my_iterator.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Good tests"){
    OrgChart chart;
    // ===============================
    // Check add_root & add_sub funcs
    // ===============================
    string order;
    int size = 0;

    CHECK_NOTHROW(chart.add_root("top1"));
    for (auto i = chart.begin_level_order(); i != chart.end_level_order(); ++i)
    {
        size++;
        order += *i;
        CHECK(*i == "top1");
    }
    CHECK(order == "top1");
    CHECK(size == 1);
    order.clear();
    size = 0;
    CHECK_NOTHROW(chart.add_sub("top1", "top2"));
    for (auto i = chart.begin_level_order(); i != chart.end_level_order(); ++i)
    {
        size++;
        order += *i;
    }
    CHECK(order == "top1top2");
    CHECK(size == 2);
    order.clear();
    size = 0;
    CHECK_NOTHROW(chart.add_sub("top1", "top3"));
    CHECK_NOTHROW(chart.add_sub("top2", "top4"));
    CHECK_NOTHROW(chart.add_sub("top2", "top5"));
    CHECK_NOTHROW(chart.add_sub("top3", "top6"));
    CHECK_NOTHROW(chart.add_sub("top3", "top7"));
    
    // ==================
    // Check level order
    // ==================

    for (auto i = chart.begin_level_order(); i != chart.end_level_order(); ++i)
    {
        size++;
        order += *i;
    }
    CHECK(order == "top1top2top3top4top5top6top7");
    CHECK(size == 7);
    order.clear();
    size = 0;
    
    // ========================================================
    // Check that root changes and the order is still the same
    // ========================================================

    CHECK_NOTHROW(chart.add_root("top8"));
    for (auto i = chart.begin_level_order(); i != chart.end_level_order(); ++i)
    {
        size++;
        order += *i;
    }
    CHECK(order == "top8top2top3top4top5top6top7");
    CHECK(size == 7);
    order.clear();
    size = 0;

    CHECK_NOTHROW(chart.add_root("top1"));

    // ===============
    // Check preorder
    // ===============

    for (auto i = chart.begin_preorder(); i != chart.end_preorder(); ++i)
    {
        size++;
        order += *i;
    }
    CHECK(order == "top1top2top4top5top3top6top7");
    CHECK(size == 7);
    order.clear();
    size = 0;

    // ==============
    // Check reverse
    // ==============

    for (auto i = chart.begin_reverse_order(); i != chart.reverse_order(); ++i)
    {
        size++;
        order += *i;
    }
    CHECK(order == "top4top5top6top7top2top3top1");
    CHECK(size == 7);
    order.clear();
    size = 0;

    // ===================================================
    // Check all orders are the same if we have only root
    // ===================================================

    OrgChart chart2;
    vector<string> level;
    vector<string> pre;
    vector<string> reverse;

    CHECK_NOTHROW(chart2.add_root("top1"));
    for (auto i = chart2.begin_reverse_order(); i != chart2.reverse_order(); ++i)
    {
        reverse.push_back(*i);
    }
    for (auto i = chart2.begin_preorder(); i != chart2.end_preorder(); ++i)
    {
        pre.push_back(*i);
    }
    for (auto i = chart2.begin_level_order(); i != chart2.end_level_order(); ++i)
    {
        level.push_back(*i);
    }

    CHECK(level.size() == 1);
    CHECK(level.size() == pre.size());
    CHECK(reverse.size() == pre.size());
    CHECK(level.at(0) == pre.at(0));
    CHECK(pre.at(0) == reverse.at(0));

    // =============================
    // Check the iterator operators
    // =============================

    for (auto i = chart2.begin_reverse_order(); i != chart2.reverse_order(); ++i)
    {
        CHECK(*i == "top1");
        CHECK(i->compare("top1") == 0);
        CHECK(i == chart2.begin_preorder());
        CHECK(i != chart2.reverse_order());
    }
    for (auto i = chart2.begin_preorder(); i != chart2.end_preorder(); ++i)
    {
        CHECK(*i == "top1");
        CHECK(i->compare("top1") ==  0);
        CHECK(i == chart2.begin_preorder());
        CHECK(i != chart2.reverse_order());
    }
    for (auto i = chart2.begin_level_order(); i != chart2.end_level_order(); ++i)
    {
        CHECK(*i == "top1");
        CHECK(i->compare("top1") == 0);
        CHECK(i == chart2.begin_preorder());
        CHECK(i != chart2.reverse_order());
    }

    // =============================================
    // Check OrgChart copy constructor & operator= 
    // =============================================

    OrgChart chart3;
    chart3.add_root("CEO")
      .add_sub("CEO", "CTO")
      .add_sub("CEO", "CFO")
      .add_sub("CEO", "COO")
      .add_sub("CTO", "VP_SW")
      .add_sub("COO", "VP_BI");

    // Copy constructor
    OrgChart chart4{chart3};

    for (auto i = chart3.begin_level_order(), j = chart4.begin_level_order();
        i != chart3.end_level_order() && j != chart4.end_level_order(); ++i, ++j)
    {
        CHECK(*i == *j);
    }
    
    // Operator=
    OrgChart chart5;
    chart5 = chart3;
    for (auto i = chart3.begin_level_order(), j = chart5.begin_level_order();
        i != chart3.end_level_order() && j != chart5.end_level_order(); ++i, ++j)
    {
        CHECK(*i == *j);
    }

    // Check Operator= when *this is not empty
    OrgChart chart6;
    chart6.add_root("temp").add_sub("temp","temp2");
    chart6 = chart3;
    for (auto i = chart3.begin_level_order(), j = chart6.begin_level_order();
        i != chart3.end_level_order() && j != chart6.end_level_order(); ++i, ++j)
    {
        CHECK(*i == *j);
    }
}


TEST_CASE("Bad tests"){
    // Same nams?
    OrgChart chart;
    OrgChart empty_chart;
    // Check add_root & add_sub funcs
    string order;
    int size = 0;
    // Build a chart
    CHECK_NOTHROW(chart.add_root("top1"));
    CHECK_NOTHROW(chart.add_sub("top1", "top2"));
    CHECK_NOTHROW(chart.add_sub("top1", "top3"));
    CHECK_NOTHROW(chart.add_sub("top2", "top4"));
    CHECK_NOTHROW(chart.add_sub("top2", "top5"));
    CHECK_NOTHROW(chart.add_sub("top3", "top6"));
    CHECK_NOTHROW(chart.add_sub("top3", "top7"));

    // ====================
    // Check invalid input
    // ====================

    // Supirior dont exist
    CHECK_THROWS(chart.add_sub("dont_exist", "top8"));
    CHECK_THROWS(chart.add_sub("dont_exist2", "dont_exist3"));

    // Check that after the addition of dont_exist it works
    CHECK_NOTHROW(chart.add_sub("top7", "dont_exist"));
    CHECK_NOTHROW(chart.add_sub("dont_exist", "top8"));

    //=============
    // Empty cases
    // ============

    // Empty input
    CHECK_THROWS(chart.add_root(""));
    CHECK_THROWS(chart.add_sub("", "top8"));
    CHECK_THROWS(chart.add_sub("top8", ""));
    CHECK_THROWS(chart.add_root(" "));
    CHECK_THROWS(chart.add_sub("top1"," "));
    CHECK_THROWS(chart.add_root("    "));

    // Empty chart
    CHECK_THROWS(empty_chart.begin_level_order());
    CHECK_THROWS(empty_chart.end_level_order());
    CHECK_THROWS(empty_chart.begin_reverse_order());
    CHECK_THROWS(empty_chart.reverse_order());
    CHECK_THROWS(empty_chart.begin_preorder());
    CHECK_THROWS(empty_chart.end_preorder());

    // Using add_sub before add_root in an empty chart
    CHECK_THROWS(empty_chart.add_sub("top1", "top2"));
    CHECK_THROWS(empty_chart.add_sub("top2", "top3"));
    CHECK_THROWS(empty_chart.add_sub("top3", "top4"));

}
