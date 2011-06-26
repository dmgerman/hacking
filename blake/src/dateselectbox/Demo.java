package dateselectbox;

import java.awt.*;
import java.awt.event.*;
import java.beans.*;
import java.util.*;
import javax.swing.*;

public class Demo extends JFrame implements PropertyChangeListener
{
    private DateButton startDateButton;
    private DateButton endDateButton;
    private Date startDate;
    private Date endDate;

    private Demo() {
	super( "DateChooser demo" );
	addWindowListener
	    (
	     new WindowAdapter() {
		     public void windowClosing( WindowEvent e ) {
			 System.exit( 0 );
		     }
		 }
	     );

	startDate = new Date();
	endDate = new Date();

	startDateButton = new DateButton();
	startDateButton.addPropertyChangeListener( "date", this );
	endDateButton = new DateButton();
	endDateButton.addPropertyChangeListener( "date", this );

	getContentPane().setLayout( new GridLayout(2,2) );
	getContentPane().add( new JLabel("Start date") );
	getContentPane().add( startDateButton );
	getContentPane().add( new JLabel("End date") );
	getContentPane().add( endDateButton );
	pack();
	setResizable( false );
    }

    public void propertyChange( PropertyChangeEvent e ) {
	DateButton db = (DateButton)e.getSource();
	if ( db == startDateButton )
	    System.out.print( "Start date changed: " );
	else
	    System.out.print( "End date changed: " );
	System.out.println( db.getDate() );
    }

    public static void main( String[] args ) {
	(new Demo()).show();
    }
}

