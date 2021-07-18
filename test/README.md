# Testing Rationale

The approach to testing design is property-based. The overall test design is done through
abstraction of properties and conditions. A property is a particular characteristic of the output
that is true. A condition is a scenario/case where the property can be exhibited.

Hierarchy of the test design:
- **Test File:** collection of similar properties or a single property that we want to test
- **Test Case:** a particular condition about the property that is true i.e. something should do something
- **Test Section:** various cases which will give an output to show the property to be true for a condition we are testing.

I use this particular hierarchy because it neatly separates properties, conditions, and
use-cases.

The `TEST_CASE` names are also descriptive to give an idea of what the test case is for and follows
a *"something should something"* format. Therefore `TEST_CASE` is not commented as it will be
redundant to rewrite what the test case is for. Comments will only be given at the top of the
file to clarify why we are testing a particular property.

Some test files will only have a single test case if the property to be tested is simple.
