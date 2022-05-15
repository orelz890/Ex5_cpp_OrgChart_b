#include "doctest.h"
#include <iostream>
#include <string>
#include <vector>
#include "OrgChart.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Good tests"){
    OrgChart chart;
    // Check add_root & add_sub funcs
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

    for (auto i = chart.begin_level_order(); i != chart.end_level_order(); ++i)
    {
        size++;
        order += *i;
    }
    CHECK(order == "top1top2top3top4top5top6top7");
    CHECK(size == 7);
    order.clear();
    size = 0;
    
    // Check that root changes
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

    // Check preorder
    for (auto i = chart.begin_preorder(); i != chart.end_preorder(); ++i)
    {
        size++;
        order += *i;
    }
    CHECK(order == "top1top2top4top5top3top6top7");
    CHECK(size == 7);
    order.clear();
    size = 0;

    // Check reverse
    for (auto i = chart.begin_reverse_order(); i != chart.reverse_order(); ++i)
    {
        size++;
        order += *i;
    }
    CHECK(order == "top4top5top6top7top2top3top1");
    CHECK(size == 7);
    order.clear();
    size = 0;

}

TEST_CASE("Bad tests"){
    // Same nams?
    OrgChart chart;
    // Check add_root & add_sub funcs
    string order;
    int size = 0;

    CHECK_NOTHROW(chart.add_root("top1"));
    CHECK_NOTHROW(chart.add_sub("top1", "top2"));
    CHECK_NOTHROW(chart.add_sub("top1", "top3"));
    CHECK_NOTHROW(chart.add_sub("top2", "top4"));
    CHECK_NOTHROW(chart.add_sub("top2", "top5"));
    CHECK_NOTHROW(chart.add_sub("top3", "top6"));
    CHECK_NOTHROW(chart.add_sub("top3", "top7"));

    CHECK_THROWS(chart.add_sub("dont_exist", "top8"));
    CHECK_NOTHROW(chart.add_sub("top7", "dont_exist"));
    CHECK_NOTHROW(chart.add_sub("dont_exist", "top8"));
    CHECK_THROWS(chart.add_sub("dont_exist2", "dont_exist3"));

}