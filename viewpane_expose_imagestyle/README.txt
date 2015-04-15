About
=====
Provides the ability to expose image style to Panel pane configuration.

Current Options
---------------
Allows you to override image style for image fields from pane configuration. 
This is handy when you want to use the same Views display for different layouts or themes. 

Installation
============

Dependencies
------------

- [Views](http://www.drupal.org/project/views)
- [Ctools](https://www.drupal.org/project/ctools)

SETTING UP
----------
1. Install and enable the module and it's dependencies.
2. Navigate to your Views administration (/admin/structure/views) and click edit on the desired View.
3. In order for your View to be used as Panels pane, make sure that your View has "Content pane" display.
4. Navigate to Pane Settings section of your View display and click on "Allow settings" link.
5. Check the checkbox that says "Expose imagestyle settings".
6. Navigate to your Panel and insert a your View Pane as content.
7. Click on the settings gear of your pane and choose "Settings". This will take you to Pane edit form.
8. Unfold the "Imagestyle" fieldset and you should see the list of all of your available fields that you can override image style for.
9. Choose desired image style from the select list of all available image styles.
10. Click "Finish" and then "Update and Save" your panel.
11. Navigate to the Panel page and verify that images of your view use an image style selected from Pane settings.

TO-DO:
1) On the Pane edit form only expose those fields that are actually relevant to the content that is being used. (Currently all of the available fields across all the content types are listed).
2) Contribute! 